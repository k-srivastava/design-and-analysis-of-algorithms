#include "string_matching.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

int* generate_shift_table(const char* string, const size_t shift_table_length)
{
    int* shift_table = malloc(sizeof(int) * shift_table_length);

    if (shift_table == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a shift table of length %zu.\n", shift_table_length);
        exit(1);
    }

    for (size_t i = 0; i < shift_table_length; i++)
        shift_table[i] = -1;

    for (size_t i = 0; i < strlen(string); i++)
        shift_table[(size_t) string[i]] = i;

    return shift_table;
}

int substring_brute_force(const char* string, const char* substring)
{
    const size_t string_length = strlen(string);
    const size_t substring_length = strlen(substring);

    if (substring_length > string_length)
        return -1;

    size_t i = 0, j = 0;
    while (i < string_length - substring_length)
    {
        while (string[i] == substring[j])
        {
            i++, j++;
            if (j == substring_length)
                return i - substring_length;
        }

        i++;
        j = 0;
    }

    return -1;
}

int substring_horspool(const char* string, const char* substring)
{
    const size_t string_length = strlen(string);
    const size_t substring_length = strlen(substring);

    if (substring_length > string_length)
        return -1;

    int* shift_table = generate_shift_table(substring, 256);

    size_t shift = 0;
    while (shift <= string_length - substring_length)
    {
        int j = substring_length - 1;

        while (j >= 0 && string[shift + j] == substring[j])
            j--;

        if (j < 0)
        {
            free(shift_table);
            return shift;
        }

        shift += int_max(j - shift_table[string[shift + j]], 1);
    }

    free(shift_table);

    return -1;
}
