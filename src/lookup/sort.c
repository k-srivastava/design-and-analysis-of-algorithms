#include "sort.h"

void merge_sorted_subarrays(const size_t left, const size_t middle, const size_t right, int array[right - left + 1])
{
    const size_t left_length = middle - left + 1;
    const size_t right_length = right - middle;

    int left_subarray[left_length], right_subarray[right_length];

    for (size_t i = 0; i < left_length; i++) { left_subarray[i] = array[left + i]; }
    for (size_t i = 0; i < right_length; i++) { right_subarray[i] = array[middle + i + 1]; }

    size_t i = 0, j = 0, k = left;
    while (i < left_length && j < right_length)
    {
        if (left_subarray[i] <= right_subarray[j]) { array[k++] = left_subarray[i++]; }
        else { array[k++] = right_subarray[j++]; }
    }

    while (i < left_length) { array[k++] = left_subarray[i++]; }
    while (j < right_length) { array[k++] = right_subarray[j++]; }
}

void merge_sort_helper(const size_t left, const size_t right, int array[right - left + 1])
{
    if (left < right)
    {
        const size_t middle = (left + right) / 2;

        merge_sort_helper(left, middle, array);
        merge_sort_helper(middle + 1, right, array);

        merge_sorted_subarrays(left, middle, right, array);
    }
}

size_t partition(const size_t low, const size_t high, int array[high - low + 1])
{
    const int pivot = array[high];
    size_t pivot_idx = low - 1;

    for (size_t j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            pivot_idx++;
            SWAP(array[pivot_idx], array[j], int);
        }
    }

    pivot_idx++;
    SWAP(array[pivot_idx], array[high], int);

    return pivot_idx;
}

void quick_sort_helper(const int low, const int high, int array[high - low + 1])
{
    if (low >= high || low < 0) { return; }

    const size_t pivot_idx = partition(low, high, array);
    quick_sort_helper(low, pivot_idx - 1, array);
    quick_sort_helper(pivot_idx + 1, high, array);
}

void heapify(const size_t length, int heap[length], const size_t idx)
{
    size_t maximum_idx = idx;
    const size_t left_idx = idx * 2 + 1;
    const size_t right_idx = idx * 2 + 2;

    if (left_idx < length && heap[left_idx] > heap[maximum_idx]) { maximum_idx = left_idx; }
    if (right_idx < length && heap[right_idx] > heap[maximum_idx]) { maximum_idx = right_idx; }

    if (maximum_idx != idx)
    {
        SWAP(heap[idx], heap[maximum_idx], int);
        heapify(length, heap, maximum_idx);
    }
}

void bubble_sort(const size_t length, int array[length])
{
    for (size_t i = 0; i < length - 1; i++)
    {
        size_t num_swaps = 0;
        for (size_t j = 0; j < length - (i + 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                SWAP(array[j], array[j + 1], int);
                num_swaps++;
            }
        }

        if (num_swaps == 0) { return; }
    }
}

void insertion_sort(const size_t length, int array[length])
{
    for (size_t i = 1; i < length; i++)
    {
        const int key = array[i];
        size_t j = i - 1;

        while (array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

void selection_sort(const size_t length, int array[length])
{
    for (size_t i = 0; i < length - 1; i++)
    {
        size_t min_idx = i;

        for (size_t j = i + 1; j < length; j++)
        {
            if (array[j] < array[min_idx]) { min_idx = j; }
        }

        if (min_idx != i) { SWAP(array[i], array[min_idx], int); }
    }
}

void merge_sort(const size_t length, int array[length]) { merge_sort_helper(0, length - 1, array); }

void quick_sort(const size_t length, int array[length]) { quick_sort_helper(0, length - 1, array); }

void heap_sort(const size_t length, int array[length])
{
    for (int i = length; i >= 0; i--) { heapify(length, array, i); }

    for (int i = length - 1; i >= 0; i--)
    {
        SWAP(array[0], array[i], int);
        heapify(i, array, 0);
    }
}
