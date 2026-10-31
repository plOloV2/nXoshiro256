/*
    This is a implementation of Xoshiro256** PRNG algorithm.

    Oryginal source:
    https://prng.di.unimi.it/xoshiro256starstar.c
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Xoshiro256.h"

typedef struct{
    uint64_t s[4];
}xoshiro256_state;


/** @brief Creates random seed to seed xoshiro algorithm throu splitmix64. */
static uint64_t create_rand_seed(){

    uint64_t seed = 0;

    FILE* f = fopen("/dev/urandom", "rb");
    
    if(f && fread(&seed, sizeof(seed), 1, f) == 1){
        fclose(f);
    } 
    else{
        if (f) fclose(f);
        seed = (uint64_t)time(NULL); 
    }

    return seed;

}


xoshiro256_state* xoshiro_init(uint64_t seed){

    if(seed == 0)
    {
        seed = create_rand_seed();
    }

    xoshiro256_state *state = (xoshiro256_state*)malloc(sizeof(xoshiro256_state));

    if(state == NULL)
        return NULL;

    uint64_t z = seed + 0x9e3779b97f4a7c15;

    for (int i = 0; i < 4; i++){

        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
        z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
        state->s[i] = z ^ (z >> 31);
        z += 0x9e3779b97f4a7c15;

    }

    return state;

}

/**@brief Circular 64bit shift. */
static inline uint64_t rotl(const uint64_t x, int k){
    return (x << k) | (x >> (64 - k));
}


uint64_t xoshiro_next(xoshiro256_state *state){
    const uint64_t result = rotl(state->s[1] * 5, 7) * 9;
    const uint64_t t = state->s[1] << 17;

    state->s[2] ^= state->s[0];
    state->s[3] ^= state->s[1];
    state->s[1] ^= state->s[2];
    state->s[0] ^= state->s[3];
    state->s[2] ^= t;
    state->s[3] = rotl(state->s[3], 45);

    return result;

}

void destroy_xoshiro(xoshiro256_state *state){

    if(state) 
        free(state);
    
}
