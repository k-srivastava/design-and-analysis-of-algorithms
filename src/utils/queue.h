#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct
{
    size_t size;
    size_t capacity;
    int* data;
} queue_t;

queue_t init_queue(size_t capacity);

void free_queue(queue_t queue);

bool insert_into_queue(queue_t* queue, int data);

int remove_from_queue(queue_t* queue);

int peek_into_queue(queue_t* queue);

#endif //QUEUE_H
