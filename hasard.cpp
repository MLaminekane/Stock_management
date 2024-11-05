//
// Created by mlami on 10/30/2024.
//

#include "hasard.h"
#include <iostream>
#include <random>
#include <windows.h>
using namespace std;

typedef std::mt19937 MyRNG;
uint64_t seed_val = GetTickCount64();
MyRNG rng;

void initialize()
{
    rng.seed((long)seed_val);
}

int recupererValeurAleatoire(int min, int max)
{
    uniform_int_distribution<uint64_t> uint_distMax(min, max);
    return (int)uint_distMax(rng);
}
