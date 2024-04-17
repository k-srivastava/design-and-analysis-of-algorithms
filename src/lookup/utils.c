#include <stdlib.h>
#include <stdio.h>

#include "utils.h"

size_t size_t_min(const size_t value_1, const size_t value_2)
{
    return value_1 < value_2 ? value_1 : value_2;
}

size_t size_t_max(const size_t value_1, const size_t value_2)
{
    return value_1 > value_2 ? value_1 : value_2;
}

int int_min(const int value_1, const int value_2)
{
    return value_1 < value_2 ? value_1 : value_2;
}

int int_max(const int value_1, const int value_2)
{
    return value_1 > value_2 ? value_1 : value_2;
}

int* generate_range(int lower_bound, int upper_bound)
{
    if (upper_bound < lower_bound)
        return NULL;

    int* range = malloc(sizeof(int) * (upper_bound - lower_bound));

    if (range == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for %d integers.\n", upper_bound - lower_bound);
        exit(1);
    }

    for (size_t i = 0; i < upper_bound - lower_bound; i++)
        range[i] = lower_bound + i;

    return range;
}
