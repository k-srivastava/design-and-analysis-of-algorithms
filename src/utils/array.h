#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>

#define DISPLAY_ARRAY(length, array, format, stream)\
    fprintf(stream, "{ ");\
    for (size_t i = 0; i < length; i++) { fprintf(stream, format, array[i]); }\
    fprintf(stream, "}\n")

#endif //ARRAY_H
