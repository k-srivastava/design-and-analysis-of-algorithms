// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#ifndef GCD_H
#define GCD_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool is_prime(const uint32_t number)
{
    if (number == 0 || number == 1) { return false; }

    for (uint32_t i = 2; i < number; i++)
    {
        if (number % i == 0) { return false; }
    }

    return true;
}

uint32_t* get_prime_factors(const uint32_t number)
{
    uint32_t* prime_factors = malloc(sizeof(uint32_t) * number);

    if (prime_factors == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for calculating prime factors of %u.\n", number);
        exit(1);
    }

    uint32_t i = 0;

    for (uint32_t j = 1; j <= number; j++)
    {
        if (number % j == 0 && is_prime(j)) { prime_factors[i++] = j; }
    }

    while (i != number) { prime_factors[i++] = 0; }

    return prime_factors;
}

uint32_t gcd_middle_school(uint32_t num_1, uint32_t num_2)
{
    uint32_t larger, smaller;

    if (num_1 > num_2)
    {
        larger = num_1;
        smaller = num_2;
    }

    else
    {
        larger = num_2;
        smaller = num_1;
    }

    uint32_t* larger_factors = get_prime_factors(larger);
    uint32_t* smaller_factors = get_prime_factors(smaller);

    uint32_t gcd = 1;

    for (uint32_t i = 0; smaller_factors[i] != 0; i++)
    {
        for (uint32_t j = 0; larger_factors[j] != 0; j++)
        {
            if (smaller_factors[i] == larger_factors[j]) { gcd *= smaller_factors[i]; }
        }
    }

    free(larger_factors);
    free(smaller_factors);

    return gcd;
}

uint32_t gcd_consecutive(const uint32_t num_1, const uint32_t num_2)
{
    uint32_t larger, smaller;

    if (num_1 > num_2)
    {
        larger = num_1;
        smaller = num_2;
    }

    else
    {
        larger = num_2;
        smaller = num_1;
    }

    for (uint32_t i = smaller; i >= 1; i--)
    {
        if (larger % i == 0 && smaller % i == 0) { return i; }
    }

    return -1;
}

#endif //GCD_H
