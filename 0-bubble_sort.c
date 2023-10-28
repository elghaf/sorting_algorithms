#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using the Bubble Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
    size_t pass, index;
    int temp, swapped;

    for (pass = 0; pass < size; pass++)
    {
        swapped = 0;
        for (index = 0; index < size - 1 - pass; index++)
        {
            if (array[index] > array[index + 1])
            {
                temp = array[index + 1];
                array[index + 1] = array[index];
                array[index] = temp;
                print_array(array, size);
                swapped = 1;
            }
        }
        if (!swapped)
        {
            return;
        }
    }
}
