
#include "Exercise.hpp"
#include "Alignment.hpp"
#include <stdio.h>
#if __cplusplus > 199711L
#include <cstdint>
#endif

#define ALIGNED1 64
#define ALIGNED2 128

unsigned char first;
#if __cplusplus > 199711L
alignas(ALIGNED1) unsigned char aligned1[5];
alignas(ALIGNED2) unsigned char aligned2[5];
#endif
unsigned char unaligned1[5];
unsigned char unaligned2[5];

void Alignment::execute()
{
    log();
#if __cplusplus > 199711L
    constexpr int n = alignof(unsigned char);
    printf("alignof(unsigned char): %i\n", n);
    printf("aligned1 mod ALIGNED1: %u\n", ((uintptr_t) aligned1) % ALIGNED1);
    printf("aligned2 mod ALIGNED2: %u\n", ((uintptr_t) aligned1) % ALIGNED2);
    printf("sizeof(first): %d @%p, sizeof(aligned1): %d @%p, sizeof(aligned2): %d @%p, sizeof(unaligned1): %d @%p, sizeof(unaligned2): %d @%p \n",
            sizeof(first), &first, sizeof(aligned1), aligned1, sizeof(aligned2), aligned2, sizeof(unaligned1), unaligned1, sizeof(unaligned2), unaligned2);
    printf("aligned1-first: %li \n", aligned1 - &first);
    printf("aligned2-aligned1: %li \n", aligned2 - aligned1);
    printf("unaligned1-aligned2: %li \n", unaligned1 - aligned2);
#endif
    printf("unaligned2-unaligned1: %li \n", unaligned2 - unaligned1);
}

