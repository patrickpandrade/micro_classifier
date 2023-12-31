################################################################################
FROM ubuntu:20.04 as builder
################################################################################

# Install devtoolset build dependencies
COPY setup.packages.sh setup.packages.sh
COPY builder.packages.txt builder.packages.txt
RUN /setup.packages.sh /builder.packages.txt

# Install devtoolset-9 in /dt10 with glibc 2.17 and libstdc++ 4.8, for building
# manylinux2014-compatible packages.
COPY builder.devtoolset/fixlinks_aarch64.sh /fixlinks.sh
COPY builder.devtoolset/rpm-patch.sh /rpm-patch.sh
COPY builder.devtoolset/build_devtoolset.sh /build_devtoolset.sh
COPY builder.devtoolset/gcc9-fixups.patch /gcc9-fixups.patch
COPY builder.devtoolset/stringop_trunc.patch /stringop_trunc.patch
RUN /build_devtoolset.sh devtoolset-10 /dt10

# Build later version of patchelf that is not so buggy
COPY builder.patchelf/build_patchelf.sh /build_patchelf.sh
COPY apt.conf /etc/apt/
RUN /build_patchelf.sh

################################################################################
FROM ubuntu:20.04 as devel
################################################################################
COPY --from=builder /dt10 /dt10
COPY --from=builder /patchelf/patchelf_0.14.3-1_arm64.deb /patchelf/patchelf_0.14.3-1_arm64.deb

# Install devtoolset devel dependencies
COPY setup.sources.sh /setup.sources.sh
COPY setup.packages.sh /setup.packages.sh
COPY devel.packages.txt /devel.packages.txt
RUN /setup.sources.sh && /setup.packages.sh /devel.packages.txt

# Install various tools.
# - bats: bash unit testing framework
#         NOTE: v1.6.0 seems to have a bug that made "git" in setup_file break
# - bazelisk: always use the correct bazel version
# - buildifier: clean bazel build deps
# - buildozer: clean bazel build deps
RUN git clone --branch v1.7.0 https://github.com/bats-core/bats-core.git && bats-core/install.sh /usr/local && rm -rf bats-core
RUN wget https://github.com/bazelbuild/bazelisk/releases/download/v1.12.0/bazelisk-linux-arm64 -O /usr/local/bin/bazel && chmod +x /usr/local/bin/bazel
RUN wget https://github.com/bazelbuild/buildtools/releases/download/4.2.5/buildifier-linux-arm64 -O /usr/local/bin/buildifier && chmod +x /usr/local/bin/buildifier
RUN wget https://github.com/bazelbuild/buildtools/releases/download/4.2.5/buildozer-linux-arm64 -O /usr/local/bin/buildozer && chmod +x /usr/local/bin/buildozer

RUN groupadd -g 1001 buildslave && useradd -m -u 1001 -g buildslave buildslave
RUN mkdir -p /tf/venv
RUN chown -R buildslave:buildslave /tf
RUN dpkg -i /patchelf/patchelf_0.14.3-1_arm64.deb

# All lines past this point are reset when $CACHEBUSTER is set. We need this
# for Python specifically because we install some nightly packages which are
# likely to change daily.
ARG CACHEBUSTER=0
RUN echo $CACHEBUSTER

# Setup build and environment
COPY devel.usertools /usertools
COPY devel.bashrc /root/.bashrc
COPY ld.so.conf /dt10/etc/

# Setup Python environment.
COPY setup.python.sh /setup.python.sh
COPY devel.requirements.txt /devel.requirements.txt
RUN /setup.python.sh python3.8 devel.requirements.txt
RUN /setup.python.sh python3.9 devel.requirements.txt
RUN /setup.python.sh python3.10 devel.requirements.txt
RUN /setup.python.sh python3.11 devel.requirements.txt

