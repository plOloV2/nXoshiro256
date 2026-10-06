/*
    This is a implementation of Xoshiro256** PRNG algorithm.

    Oryginal source:
    https://prng.di.unimi.it/xoshiro256starstar.c
*/

#ifndef XOSHIRO256_H
#define XOSHIRO256_H

#include <stdint.h>

typedef struct xoshiro256_state xoshiro256_state;

uint64_t xoshiro_next(xoshiro256_state *state);
void destroy_xoshiro(xoshiro256_state *state);
xoshiro256_state* xoshiro_init();

#endif
