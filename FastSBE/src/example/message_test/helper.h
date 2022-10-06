#pragma once

#include <cstdlib>
#include <iostream>
#include <ctime>

inline int get_random_int(int base)
{
    std::srand(std::time(nullptr));
    int xrandom_variable = 1 + std::rand()/((RAND_MAX + 1u)/base);
    return xrandom_variable;
}