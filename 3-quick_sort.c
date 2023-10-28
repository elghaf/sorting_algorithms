#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * quick_sort - Sort an array of integers in ascending order
 *                         using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Custom Description: This function sorts the array using selection sort
 * and prints the array after each swap.
 */
void quick_sort(int *array, size_t size)
{
    int *current_min;
    size_t outer_index, inner_index;
    int is_swapped = 0;

    if (array == NULL || size < 2)
        return;

    outer_index = 0;
    do
    {
        current_min = array + outer_index;
        for (inner_index = outer_index + 1; inner_index < size; inner_index++)
            current_min = (array[inner_index] < *current_min) ? (array + inner_index) : current_min;

        if ((array + outer_index) != current_min)
        {
            swap_ints(array + outer_index, current_min);
            is_swapped = 1;
        }

        if (is_swapped)
        {
            print_array(array, size);
            is_swapped = 0;
        }

        outer_index++;
    } while (outer_index < size - 1);
}
