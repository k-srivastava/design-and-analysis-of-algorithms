// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#ifndef TRAVELLING_SALESMAN_H
#define TRAVELLING_SALESMAN_H

#include <stddef.h>

#include "assignment.h"

int calculate_distance() {}

int find_ideal_distance(const size_t num_cities, int distances[num_cities][num_cities])
{
    int* permutation = generate_range(0, num_cities);
    bool generated_last_permutation = false;

    int total_cost = calculate_distance(num_cities, distances, permutation);

    while (!generated_last_permutation)
    {
        int j = -1;
        for (size_t i = 0; i < num_cities; i++)
        {
            if (permutation[i + 1] > permutation[i]) { j = i; }
        }

        if (j == -1) { generated_last_permutation = true; }

        if (!generated_last_permutation)
        {
            size_t l = 0;

            for (size_t i = j + 1; i < num_cities; i++)
            {
                if (permutation[i] > permutation[j]) { l = i; }
            }

            const int temp_1 = permutation[j];
            permutation[j] = permutation[l];
            permutation[l] = temp_1;

            const size_t k = (num_cities - 1 - j) / 2;
            for (size_t i = 0; i < k; i++)
            {
                const int temp_2 = permutation[i + j + 1];
                permutation[i + j + 1] = permutation[num_cities - i - 1];
                permutation[num_cities - i - 1] = temp_2;
            }

            if (permutation[0] == 0 && permutation[num_cities] == num_cities - 1)
            {
                const int current_cost = calculate_distance(num_cities, distances, permutation);
                if (current_cost < total_cost) { total_cost = current_cost; }
            }
        }
    }

    free(permutation);

    return total_cost;
}

#endif //TRAVELLING_SALESMAN_H
