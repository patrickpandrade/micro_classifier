load("//tensorflow:tensorflow.bzl", "tf_cc_test")

# copybara:uncomment package(default_applicable_licenses = ["//tensorflow:license"])

cc_library(
    name = "rematerializer",
    srcs = ["rematerializer.cc"],
    hdrs = ["rematerializer.h"],
    deps = [
    ],
)

tf_cc_test(
    name = "rematerializer_test",
    size = "small",
    srcs = ["rematerializer_test.cc"],
    deps = [
        ":rematerializer",
        "@com_google_googletest//:gtest_main",
    ],
)
