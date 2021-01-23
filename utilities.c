#include <math.h>
#include <stdint.h>
#include <stdio.h>

// stack overflow gave me this function
uint32_t ipow(uint32_t base, uint32_t exp) {
    if (base == 0) {
        return 0;
    }
    uint32_t result = 1;
    for (;;) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}