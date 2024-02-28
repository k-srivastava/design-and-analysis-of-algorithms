// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#ifndef PARTITION_H
#define PARTITION_H

#include <stdbool.h>
#include <stddef.h>

bool subset_sum_equals(const size_t length, int set[length], const int sum)
{
    if (sum == 0) { return true; }
    if (length == 0) { return false; }

    if (set[length - 1] > sum) { return subset_sum_equals(length - 1, set, sum); }
    return subset_sum_equals(length - 1, set, sum) || subset_sum_equals(length - 1, set, sum - set[length - 1]);
}

bool find_partition(size_t length, int set[length])
{
    int sum = 0;
    for (size_t i = 0; i < length; i++) { sum += set[i]; }

    if (sum % 2 != 0) { return false; }
    return subset_sum_equals(length, set, sum / 2);
}

#endif //PARTITION_H
