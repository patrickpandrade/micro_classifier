// Copyright 2023 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <utility>
#include <vector>

#include "Eigen/Core"  // from @eigen_archive
#include "tensorflow/lite/builtin_ops.h"
#include "tensorflow/lite/core/c/builtin_op_data.h"
#include "tensorflow/lite/core/c/common.h"
#include "tensorflow/lite/core/subgraph.h"
#include "tensorflow/lite/kernels/internal/runtime_shape.h"
#include "tensorflow/lite/kernels/internal/tensor_ctypes.h"
#include "tensorflow/lite/kernels/internal/types.h"
#include "tensorflow/lite/kernels/kernel_util.h"

namespace tflite {
namespace ops {
namespace builtin {
namespace stablehlo_scatter {
namespace {

constexpr int kInputsTensor = 0;
constexpr int kScatterIndicesTensor = 1;
constexpr int kUpdatesTensor = 2;
constexpr int kOutputTensor = 0;

// Indicates the type of the computation performed in the op region of the
// scatter kernel.
enum class ComputationType {
  kUpdate,
  kAdd,
  kMultiply,
  kMaximum,
  kMinimum,
  kOther
};

// Contains the data that the operation sets in the Prepare phase and uses in
// the Eval phase.
struct OpData {
  ComputationType computation_type;
};

// Element i contains the index of an entry in the i-th dimension.
template <typename IndexType>
using Index = std::vector<IndexType>;

// Contains a vector with each element being a dimension index
// example: [1, 4] means the second and fifth dimensions of another vector.
using DimVector = std::vector<int64_t>;

// Returns true if `value` is found in `array`.
static bool ArrayContains(const int64_t* array, int size, int64_t value) {
  if (size == 0) {
    return false;
  }
  return std::find(array, array + size, value) != array + size;
}

// Returns the update scatter dimension given the update window dimensions.
// Example:
// When updates_rank=5, update_window_dims=[2, 4]
// it returns [0, 1, 3]
static DimVector GetUpdateScatterDims(int64_t updates_rank,
                                      const int64_t* update_window_dims,
                                      int num_update_window_dims) {
  DimVector result;
  for (int64_t dim = 0; dim < updates_rank; ++dim) {
    if (!ArrayContains(update_window_dims, num_update_window_dims, dim)) {
      result.push_back(dim);
    }
  }
  return result;
}

// Creates a new Index from a given one that contains only the asked dimensions.
// Example: If update_index is [i,j,k,l,m] and update_scatter_dims
// is [1, 3, 4], the result is [j, l, m]
template <typename IndexType>
static Index<IndexType> GatherIndex(const Index<IndexType>& index,
                                    const DimVector& dims) {
  Index<IndexType> result;
  for (auto dim : dims) {
    result.push_back(index[dim]);
  }
  return result;
}

// Checks if the given index is within the bounds of the provided shape.
template <typename IndexType>
static bool IsInBounds(Index<IndexType> index, RuntimeShape shape) {
  if (index.size() != shape.DimensionsCount()) {
    return false;
  }

  for (int dim = 0; dim < shape.DimensionsCount(); ++dim) {
    // int32 is implicitly promoted to int64 if needed.
    if (index[dim] >= shape.Dims(dim)) {
      return false;
    }
  }
  return true;
}

static ComputationType OpCodeToComputationType(int op_code) {
  switch (op_code) {
    case kTfLiteBuiltinAdd:
      return ComputationType::kAdd;
    case kTfLiteBuiltinMul:
      return ComputationType::kMultiply;
    case kTfLiteBuiltinMaximum:
      return ComputationType::kMaximum;
    case kTfLiteBuiltinMinimum:
      return ComputationType::kMinimum;
    default:
      return ComputationType::kOther;
  }
}

// Inspects the scatter op region subgraph and extracts the right
// ComputationType from the nodes of the Subgraph.
static TfLiteStatus GetComputationType(const Subgraph* computation_subgraph,
                                       ComputationType* computation_type,
                                       TfLiteContext* context) {
  if (computation_subgraph->execution_plan().empty()) {
    *computation_type = ComputationType::kUpdate;
    return kTfLiteOk;
  }
  if (computation_subgraph->execution_plan().size() > 1) {
    TF_LITE_KERNEL_LOG(context,
                       "Only one kernel allowed withing the stablehlo region. "
                       "(%i) kernels found.\n",
                       computation_subgraph->execution_plan().size());
    return kTfLiteError;
  }

  // Safe to assume execution_plan has one element here since we checked for
  // other cases prior to this.
  const TfLiteRegistration* kernel =
      &(computation_subgraph
            ->node_and_registration(computation_subgraph->execution_plan()[0])
            ->second);

  *computation_type = OpCodeToComputationType(kernel->builtin_code);
  if (*computation_type == ComputationType::kOther) {
    TF_LITE_KERNEL_LOG(
        context,
        "Only update, Add, Multiply, Maximum and Minimum operations are "
        "currently supported for stablehlo.scatter.");
    return kTfLiteError;
  }
  return kTfLiteOk;
}

// Creates a new Index based on the provided scatter_dims.
// Example:
// For index={s0, s1}, scatter_dims_to_operand_dims=[1, 0], returns {s2,s1,0}.
// Result has same size as rank of input. All the result dimensions not in
// scatter_dims_to_operand_dims get the value 0.
template <typename IndexType>
static TfLiteStatus ScatterIndex(const Index<IndexType>& index,
                                 const int64_t* scatter_dims,
                                 int num_scatter_dims, int64_t to_rank,
                                 Index<IndexType>* result) {
  if (result == nullptr) {
    return kTfLiteError;
  }

  *result = Index<IndexType>(to_rank, 0);
  for (int idx = 0; idx < num_scatter_dims; ++idx) {
    if (scatter_dims[idx] >= result->size()) {
      return kTfLiteError;
    }
    (*result)[scatter_dims[idx]] = index[idx];
  }
  return kTfLiteOk;
}

// A helper function that converts a tensor index into a flat array index.
template <typename IndexType>
static IndexType TensorIndexToFlat(const IndexType* index, const int64_t dims,
                                   const RuntimeShape& shape) {
  // If it's a scalar, just return the index of the first element.
  if (dims == 0) {
    return 0;
  }
  IndexType flat_index = index[0];
  for (int64_t i = 1; i < dims; ++i) {
    flat_index = flat_index * shape.Dims(i) + index[i];
  }
  return flat_index;
}

template <typename IndexType>
static Index<IndexType> AddIndices(const Index<IndexType>& index1,
                                   const Index<IndexType>& index2) {
  Index<IndexType> result;
  result.reserve(index1.size());
  for (int64_t dim = 0; dim < index1.size(); ++dim) {
    result.push_back(index1[dim] + index2[dim]);
  }
  return result;
}

// Applies the provided computation to `input_value` and `update_value` and
// stores the result in `tensor[index]`.
template <typename DataType, typename IndexType>
static TfLiteStatus ApplyComputation(TfLiteTensor* tensor,
                                     Index<IndexType> index,
                                     DataType input_value,
                                     DataType update_value,
                                     ComputationType computation_type,
                                     TfLiteContext* context) {
  DataType* tensor_data = GetTensorData<DataType>(tensor);

  DataType result;
  if (computation_type == ComputationType::kUpdate) {
    result = update_value;
  } else if (computation_type == ComputationType::kAdd) {
    result = input_value + update_value;
  } else if (computation_type == ComputationType::kMultiply) {
    result = input_value * update_value;
  } else if (computation_type == ComputationType::kMaximum) {
    result = std::max(input_value, update_value);
  } else if (computation_type == ComputationType::kMinimum) {
    result = std::min(input_value, update_value);
  } else {
    TF_LITE_KERNEL_LOG(context,
                       "Provided kernel in the stablehlo scatter region is not "
                       "yet supported.");
    return kTfLiteError;
  }

  tensor_data[TensorIndexToFlat(index.data(), index.size(),
                                GetTensorShape(tensor))] = result;
  return kTfLiteOk;
}

// Creates a new Index with the number of dimensions increased with respect to
// inserted_dims array.
// Example: index=[i, j], inserted_window_dims=[1], the result is [i, 0, j]
template <typename IndexType>
static TfLiteStatus ExpandDims(const Index<IndexType>& index,
                               const int64_t* inserted_dims,
                               int num_inserted_dims,
                               Index<IndexType>* result) {
  std::vector<int64_t> scatter_dims;
  scatter_dims.reserve(index.size());
  int64_t ctr = 0;
  for (int idx = 0; idx < index.size(); ++idx) {
    while (ArrayContains(inserted_dims, num_inserted_dims, ctr)) {
      ++ctr;
    }
    scatter_dims.push_back(ctr);
    ++ctr;
  }
  TF_LITE_ENSURE_STATUS(ScatterIndex(index, scatter_dims.data(),
                                     scatter_dims.size(),
                                     index.size() + num_inserted_dims, result));
  return kTfLiteOk;
}

// Reads one array from a given tensor.
// Example: other_indices=[j, l, m], dim_to_read= 2
// The resulting read array is: [j, l, :, m]
template <typename IndexType>
static Index<IndexType> ReadScatterIndicesAxis(
    const TfLiteTensor* scatter_indices, const RuntimeShape& tensor_shape,
    const Index<IndexType>& other_indices, int64_t dim_to_read) {
  Index<IndexType> index;
  index.reserve(tensor_shape.DimensionsCount());
  int shift = 0;
  for (int64_t dim = 0; dim < tensor_shape.DimensionsCount(); ++dim) {
    if (dim == dim_to_read) {
      index.push_back(0);
      shift = 1;
    } else {
      index.push_back(other_indices[dim - shift]);
    }
  }
  int64_t index_vector_size = tensor_shape.Dims(dim_to_read);
  Index<IndexType> result;
  result.reserve(index_vector_size);
  for (IndexType index_vector_idx = 0; index_vector_idx < index_vector_size;
       ++index_vector_idx) {
    index[dim_to_read] = index_vector_idx;

    IndexType flat_index = TensorIndexToFlat(
        index.data(), tensor_shape.DimensionsCount(), tensor_shape);
    const IndexType* tensor_data = GetTensorData<IndexType>(scatter_indices);
    result.push_back(tensor_data[flat_index]);
  }
  return result;
}

// Evaluates this node given the type of the elements in the scatter_indices
// and the type of the elements in the input/updates vector.
template <typename IndexType, typename DataType>
TfLiteStatus EvalWithTypes(TfLiteContext* context, TfLiteNode* node) {
  OpData* op_data = reinterpret_cast<OpData*>(node->user_data);

  const TfLiteStablehloScatterParams* data =
      reinterpret_cast<TfLiteStablehloScatterParams*>(node->builtin_data);

  const TfLiteTensor* input;
  TF_LITE_ENSURE_OK(context,
                    GetInputSafe(context, node, kInputsTensor, &input));
  const TfLiteTensor* scatter_indices;
  TF_LITE_ENSURE_OK(context, GetInputSafe(context, node, kScatterIndicesTensor,
                                          &scatter_indices));
  const TfLiteTensor* updates;
  TF_LITE_ENSURE_OK(context,
                    GetInputSafe(context, node, kUpdatesTensor, &updates));

  TfLiteTensor* output;
  TF_LITE_ENSURE_OK(context,
                    GetOutputSafe(context, node, kOutputTensor, &output));

  // First copy all of the data to the output before applying the updates.
  memcpy(output->data.data, input->data.data, input->bytes);

  RuntimeShape input_shape = GetTensorShape(input);
  int input_rank = input_shape.DimensionsCount();

  const DataType* output_data = GetTensorData<DataType>(output);
  RuntimeShape scatter_indices_shape = GetTensorShape(scatter_indices);
  RuntimeShape updates_shape = GetTensorShape(updates);
  int64_t updates_rank = updates_shape.DimensionsCount();
  Index<IndexType> update_index = Index<IndexType>(updates_rank, 0);
  const DataType* updates_data = GetTensorData<DataType>(updates);

  // Find the batch dimensions for when we see an update index
  DimVector update_scatter_dims = GetUpdateScatterDims(
      updates_rank, data->update_window_dims, data->num_update_window_dims);

  std::vector<int64_t> update_window_dims_vec(
      data->update_window_dims,
      data->update_window_dims + data->num_update_window_dims);

  do {
    Index<IndexType> update_scatter_index =
        GatherIndex(update_index, update_scatter_dims);

    // Read the index_vector_dim dimension with the other dimension indices set.
    // Let's say the contents after reading are {s1, s2}
    Index<IndexType> start_index =
        ReadScatterIndicesAxis(scatter_indices, scatter_indices_shape,
                               update_scatter_index, data->index_vector_dim);

    Index<IndexType> full_start_index;
    TF_LITE_ENSURE_STATUS(ScatterIndex(
        start_index, data->scatter_dims_to_operand_dims,
        data->num_scatter_dims_to_operand_dims, input_rank, &full_start_index));

    // If update_index is [i, j, k] and  update_window_dims is [0, 2] the result
    // is [i, k].
    Index<IndexType> window_index =
        GatherIndex(update_index, update_window_dims_vec);

    // With the inserted_window_dims being [1], the result is [i, 0, k]
    Index<IndexType> full_window_index;
    TF_LITE_ENSURE_STATUS(ExpandDims(window_index, data->inserted_window_dims,
                                     data->num_inserted_window_dims,
                                     &full_window_index));

    Index<IndexType> result_index =
        AddIndices(full_start_index, full_window_index);

    // The spec says, this behaviour is implementation-dependent. We follow the
    // reference interpreter where it ignores the updates that target out of
    // bounds result indices.
    if (!IsInBounds(result_index, input_shape)) {
      continue;
    }

    DataType input_value = output_data[TensorIndexToFlat(
        result_index.data(), input_rank, input_shape)];

    DataType update_value = updates_data[TensorIndexToFlat(
        update_index.data(), updates_rank, updates_shape)];

    TF_LITE_ENSURE_STATUS(ApplyComputation(output, result_index, input_value,
                                           update_value,
                                           op_data->computation_type, context));
  } while (
      NextIndex(updates_rank, updates_shape.DimsData(), update_index.data()));

  return TfLiteStatus::kTfLiteOk;
}

// Evaluates this node given the type of the elements in the scatter_indices
// tensor.
template <typename IndexType>
TfLiteStatus EvalWithIndexType(TfLiteContext* context, TfLiteNode* node,
                               TfLiteType index_type, TfLiteType data_type) {
  switch (data_type) {
    case kTfLiteFloat16:
      return EvalWithTypes<IndexType, Eigen::half>(context, node);
    case kTfLiteFloat32:
      return EvalWithTypes<IndexType, float>(context, node);
    case kTfLiteFloat64:
      return EvalWithTypes<IndexType, double>(context, node);
    case kTfLiteInt8:
      return EvalWithTypes<IndexType, int8_t>(context, node);
    case kTfLiteInt16:
      return EvalWithTypes<IndexType, int16_t>(context, node);
    case kTfLiteInt32:
      return EvalWithTypes<IndexType, int32_t>(context, node);
    case kTfLiteInt64:
      return EvalWithTypes<IndexType, int64_t>(context, node);
    case kTfLiteUInt8:
      return EvalWithTypes<IndexType, uint8_t>(context, node);
    case kTfLiteUInt16:
      return EvalWithTypes<IndexType, uint16_t>(context, node);
    case kTfLiteUInt32:
      return EvalWithTypes<IndexType, uint32_t>(context, node);
    case kTfLiteUInt64:
      return EvalWithTypes<IndexType, uint64_t>(context, node);
    default:
      TF_LITE_KERNEL_LOG(
          context, "(Index Type: %s, Data Type: %s) currently not supported.\n",
          TfLiteTypeGetName(index_type), TfLiteTypeGetName(data_type));
      return TfLiteStatus::kTfLiteError;
  }
}

void* Init(TfLiteContext* context, const char* buffer, size_t length) {
  return new ComputationType{ComputationType::kOther};
}

void Free(TfLiteContext* context, void* buffer) {
  delete reinterpret_cast<ComputationType*>(buffer);
}

TfLiteStatus Prepare(TfLiteContext* context, TfLiteNode* node) {
  TF_LITE_ENSURE_EQ(context, NumInputs(node), 3);
  TF_LITE_ENSURE_EQ(context, NumOutputs(node), 1);

  const TfLiteTensor* input;
  TF_LITE_ENSURE_OK(context,
                    GetInputSafe(context, node, kInputsTensor, &input));

  TfLiteTensor* output;
  TF_LITE_ENSURE_OK(context,
                    GetOutputSafe(context, node, kOutputTensor, &output));

  // Need the copy since ResizeTensor takes ownership of output_size
  TfLiteIntArray* output_size = TfLiteIntArrayCopy(input->dims);
  TF_LITE_ENSURE_STATUS(context->ResizeTensor(context, output, output_size));

  const TfLiteStablehloScatterParams* data =
      reinterpret_cast<TfLiteStablehloScatterParams*>(node->builtin_data);
  Subgraph* this_subgraph = reinterpret_cast<Subgraph*>(context->impl_);
  auto* subgraphs = this_subgraph->GetSubgraphs();

  if (data->update_computation_subgraph_index >= subgraphs->size()) {
    TF_LITE_KERNEL_LOG(context,
                       "Computation subgraph not found for stablehlo.scatter.");
    return TfLiteStatus::kTfLiteError;
  }

  Subgraph* computation_subgraph =
      (*subgraphs)[data->update_computation_subgraph_index].get();

  OpData* op_data = reinterpret_cast<OpData*>(node->user_data);
  TF_LITE_ENSURE_STATUS(GetComputationType(
      computation_subgraph, &op_data->computation_type, context));

  return TfLiteStatus::kTfLiteOk;
}

}  // namespace

TfLiteStatus Eval(TfLiteContext* context, TfLiteNode* node) {
  const TfLiteTensor* input;
  TF_LITE_ENSURE_OK(context,
                    GetInputSafe(context, node, kInputsTensor, &input));
  const TfLiteTensor* scatter_indices;
  TF_LITE_ENSURE_OK(context, GetInputSafe(context, node, kScatterIndicesTensor,
                                          &scatter_indices));

  TfLiteType index_type = scatter_indices->type;
  TfLiteType data_type = input->type;

  if (index_type == kTfLiteInt32) {
    return EvalWithIndexType<int32_t>(context, node, index_type, data_type);
  } else if (index_type == kTfLiteInt64) {
    return EvalWithIndexType<int64_t>(context, node, index_type, data_type);
  } else {
    TF_LITE_KERNEL_LOG(context, "(Index Type: %s) currently not supported.\n",
                       TfLiteTypeGetName(index_type));
    return TfLiteStatus::kTfLiteError;
  }
}

}  // namespace stablehlo_scatter

TfLiteRegistration* Register_STABLEHLO_SCATTER() {
  static TfLiteRegistration r = {
      stablehlo_scatter::Init, stablehlo_scatter::Free,
      stablehlo_scatter::Prepare, stablehlo_scatter::Eval};
  return &r;
}

}  // namespace builtin
}  // namespace ops
}  // namespace tflite
