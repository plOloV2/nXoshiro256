/*
    This is a implementation of Xoshiro256** PRNG algorithm.

    Oryginal source:
    https://prng.di.unimi.it/xoshiro256starstar.c
*/

#ifndef XOSHIRO256_H
#define XOSHIRO256_H

#include <stdint.h>

/** @brief Main struct holding 256-bit algorithm state. */
typedef struct xoshiro256_state xoshiro256_state;

/**
 * @brief Generate random 64-bit number.
 * 
 * @param state pointer to xoshiro256_state struct.
 * 
 * @returns Semi random 64-bit number.
 */
uint64_t xoshiro_next(xoshiro256_state *state);

/**
 * @brief Free memory from xoshiro256_state.
 * 
 * @param state pointer to xoshiro256_state struct to be freed.
 */
void destroy_xoshiro(xoshiro256_state *state);

/**
 * @brief Creates initialized xoshiro256_state
 * 
 * @param seed user provided seed for algorithm, 0 equals random seed created by algorithm.
 * 
 * @returns Pointer to valid xoshiro256_state struct.
 */
xoshiro256_state* xoshiro_init(uint64_t seed);

#endif
