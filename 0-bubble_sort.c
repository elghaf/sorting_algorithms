#include <stdio.h>
#include "sort.h"

/**
 * custom_swap - Swaps two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void custom_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
    size_t custom_index1, custom_index2;
    int custom_swapped;

    if (array == NULL || size < 2)
        return;

    for (custom_index1 = 0; custom_index1 < size - 1; custom_index1++)
    {
        custom_swapped = 0;

        for (custom_index2 = 0; custom_index2 < size - 1 - custom_index1; custom_index2++)
        {
            if (array[custom_index2] > array[custom_index2 + 1])
            {
                custom_swap(&array[custom_index2], &array[custom_index2 + 1]);
                custom_swapped = 1;
                print_array(array, size);
            }
        }

        if (custom_swapped == 0)
            break;
    }
}
