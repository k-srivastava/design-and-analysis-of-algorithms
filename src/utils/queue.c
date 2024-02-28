#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

queue_t init_queue(const size_t capacity)
{
    queue_t queue;
    queue.data = malloc(sizeof(int) * capacity);

    if (queue.data == NULL)
    {
        fprintf(stderr, "Could not allocate a queue of %zu ints.\n", capacity);
        exit(1);
    }

    queue.size = 0;
    queue.capacity = capacity;

    return queue;
}

void free_queue(queue_t queue)
{
    free(queue.data);
    queue.data = NULL;
}

bool insert_into_queue(queue_t* queue, int data)
{
    if (queue->size == queue->capacity)
    {
        fprintf(stderr, "Queue of capacity %zu is full.\n");
        return false;
    }


}
