FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential cmake libz-dev clang

COPY . /repo
WORKDIR /repo/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX=/install
RUN make -j8
RUN make install
RUN clang++ /repo/mayhem/fuzz_hdr_base64_decoded_len.cpp -fsanitize=fuzzer,address -L /install/lib/ -lhdr_histogram_static -o /fuzz

FROM ubuntu:20.04 as package
COPY --from=builder /install /install
COPY --from=builder /fuzz /fuzz_hdr_base64_decoded_len
ENV LD_LIBRARY_PATH=/install/lib
