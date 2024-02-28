#ifndef SORT_H
#define SORT_H

#include <stdbool.h>
#include <stdlib.h>

#define SWAP(value_1, value_2, type)\
    do\
    {\
        type* temp = malloc(sizeof(type));\
        *temp = value_1;\
        value_1 = value_2;\
        value_2 = *temp;\
        free(temp);\
    }\
    while (false);


void bubble_sort(size_t length, int array[length]);

void insertion_sort(size_t length, int array[length]);

void selection_sort(size_t length, int array[length]);

void merge_sort(size_t length, int array[length]);

void quick_sort(size_t length, int array[length]);

#endif //SORT_H
