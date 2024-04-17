#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

#define SWAP(value_1, value_2, type)\
    do\
    {\
        const type temp = value_1;\
        value_1 = value_2;\
        value_2 = temp;\
    }\
    while (false)

inline size_t size_t_min(size_t value_1, size_t value_2);

inline size_t size_t_max(size_t value_1, size_t value_2);

inline int int_min(int value_1, int value_2);

inline int int_max(int value_1, int value_2);

int* generate_range(int lower_bound, int upper_bound);

#endif //UTILS_H
