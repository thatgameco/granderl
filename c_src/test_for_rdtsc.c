#include "rdtsc.h"
#include <stdio.h>

int main(void)
{
    uint64_t t, u;
    printf("[Before] t=%lu, u=%lu\n", t, u);
    rdtsc(&t, &u);
    printf("[After] t=%lu, u=%lu\n", t, u);
    return 0;
}
