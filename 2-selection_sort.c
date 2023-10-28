#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection Sort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
    int swap_temp;
    size_t current_index, compare_index, min_index;

    current_index = 0;
    do
    {
        min_index = current_index;
        compare_index = current_index + 1;

        do
        {
            if (array[compare_index] < array[min_index])
                min_index = compare_index;
            compare_index++;
        } while (compare_index < size);

        if (min_index != current_index)
        {
            swap_temp = array[current_index];
            array[current_index] = array[min_index];
            array[min_index] = swap_temp;
            print_array(array, size);
        }
        current_index++;
    } while (current_index < size - 1);
}
