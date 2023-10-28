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
 * bubble_sort - bubble Sort an array of integers.
 * @array: Array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array.
 */
void custom_bubble_sort(int *custom_array, size_t custom_size)
{
    size_t custom_i, custom_len = custom_size;
    bool custom_bubbly;

    if (custom_array == NULL || custom_size < 2)
        return;

    do
    {
        custom_bubbly = false;
        for (custom_i = 0; custom_i < custom_len - 1; custom_i++)
        {
            if (custom_array[custom_i] > custom_array[custom_i + 1])
            {
                custom_swap_ints(custom_array + custom_i, custom_array + custom_i + 1);
                custom_print_array(custom_array, custom_size);
                custom_bubbly = true;
            }
        }
        custom_len--;
    } while (custom_bubbly);
}

