// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#ifndef FIBONACCI_H
#define FIBONACCI_H
#include <stddef.h>

size_t fibonacci_recursive(const size_t number)
{
    if (number == 0 || number == 1) { return number; }
    return fibonacci_recursive(number - 1) + fibonacci_recursive(number - 2);
}

size_t fibonacci_iterative(const size_t number)
{
    if (number == 0  || number == 1) { return number; }

    size_t start = 0, current = 1;
    for (size_t i = 0; i < number - 1; i++)
    {
        const size_t temp = current;
        current += start;
        start = temp;
    }

    return current;
}

#endif //FIBONACCI_H
