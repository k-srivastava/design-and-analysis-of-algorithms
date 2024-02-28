// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <string.h>

void bubble_sort_ints(const size_t length, int array[length])
{
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 0; j < length - (i + 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                const int temp = array[i];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void bubble_sort_string(char* string)
{
    const size_t length = strlen(string);
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 0; j < length - (i + 1); j++)
        {
            if (string[j] > string[j + 1])
            {
                const char temp = string[j];
                string[j] = string[j + 1];
                string[j + 1] = temp;
            }
        }
    }
}

#endif //SORT_H
