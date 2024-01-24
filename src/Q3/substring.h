// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdbool.h>
#include <string.h>

bool is_substring(const char* source, const char* substring)
{
    const size_t source_length = strlen(source);
    const size_t substring_length = strlen(substring);

    size_t i = 0;
    size_t j = 0;

    while (i < source_length)
    {
        while (source[i] == substring[j])
        {
            i++;
            j++;

            if (j == substring_length) return true;
            if (i == source_length) return false;
        }

        i++;
        j = 0;
    }

    return false;
}

#endif //SUBSTRING_H
