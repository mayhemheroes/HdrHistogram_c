#include <stdint.h>
#include <stdio.h>
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>

extern "C" size_t hdr_base64_decoded_len(size_t encoded_size);

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    size_t encoded_size = provider.ConsumeIntegral<size_t>();
    hdr_base64_decoded_len(encoded_size);

    return 0;
}