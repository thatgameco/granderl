#pragma once

#include <stdint.h>

#ifdef __amd64
inline void rdtsc(uint64_t *t, uint64_t *u)
{
    asm volatile ("rdtsc" : "=a" (*t), "=d" (*u));
}
#elif defined(__aarch64__) && defined(__APPLE__)
#include <mach/mach_time.h>

inline void rdtsc(uint64_t *t, uint64_t *u __attribute__((unused)))
{
    *t = mach_absolute_time();
}
#elif defined(__aarch64__)
inline void rdtsc(uint64_t *t, uint64_t *u __attribute__((unused)))
{
    // https://stackoverflow.com/questions/40454157/is-there-an-equivalent-instruction-to-rdtsc-in-arm
    asm volatile ("mrs %0, cntvct_el0" : "=r" (*t));
}
#else
#error "Read your platform's perf counter here"
#endif
