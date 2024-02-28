// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "../lookup/sort.h"

int* generate_range(const size_t lower_bound, const size_t upper_bound)
{
    int* range = malloc(sizeof(int) * (upper_bound - lower_bound));

    if (range == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for %zu ints.\n", upper_bound - lower_bound);
        exit(1);
    }

    for (size_t i = 0; i < upper_bound - lower_bound; i++) { range[i] = lower_bound + i; }
    return range;
}

int calculate_cost(const size_t jobs, int costs[jobs][jobs], int permutation[jobs])
{
    int total_cost = 0;
    for (size_t i = 0; i < jobs; i++) { total_cost += costs[i][permutation[i]]; }
    return total_cost;
}

int find_ideal_assignment(const size_t jobs, int costs[jobs][jobs])
{
    int* permutation = generate_range(0, jobs);
    bool generated_last_permutation = false;

    int total_cost = calculate_cost(jobs, costs, permutation);

    while (!generated_last_permutation)
    {
        int j = -1;
        for (size_t i = 0; i < jobs; i++)
        {
            if (permutation[i + 1] > permutation[i]) { j = i; }
        }

        if (j == -1) { generated_last_permutation = true; }

        if (!generated_last_permutation)
        {
            size_t l = 0;

            for (size_t i = j + 1; i < jobs; i++)
            {
                if (permutation[i] > permutation[j]) { l = i; }
            }

            SWAP(permutation[j], permutation[l], int);

            const size_t k = (jobs - 1 - j) / 2;
            for (size_t i = 0; i < k; i++)
            {
                SWAP(permutation[i + j + 1], permutation[jobs - i - 1], int);
            }

            const int current_cost = calculate_cost(jobs, costs, permutation);
            if (current_cost < total_cost) { total_cost = current_cost; }
        }
    }

    free(permutation);
    return total_cost;
}

#endif //ASSIGNMENT_H
