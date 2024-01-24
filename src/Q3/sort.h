// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void bubble_sort(const size_t length, int array[length])
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

#endif //SORT_H
