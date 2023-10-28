#include "sort.h"

/**
 * swap - swaps the positions of two elements in an array
 * @one: pointer to the first integer
 * @two: pointer to the second integer
 */
void swap(int *one, int *two)
{
    int tmp = *one;
    *one = *two;
    *two = tmp;
}

/**
 * shell_sort - sorts an array of integers.
 * Knuth sequence method
 * @array: array of integers
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    size_t knuth_gap, outer, inner;

    for (knuth_gap = 1; knuth_gap < size / 3; knuth_gap = 3 * knuth_gap + 1);

    do
    {
        int elements_swapped = 0;

        for (outer = knuth_gap; outer < size; outer++)
        {
            int current_element = array[outer];
            size_t inner_iterator;

            for (inner_iterator = outer; inner_iterator >= knuth_gap && array[inner_iterator - knuth_gap] > current_element; inner_iterator -= knuth_gap)
            {
                swap(&array[inner_iterator], &array[inner_iterator - knuth_gap]);
            }

            array[inner_iterator] = current_element;
            elements_swapped = 1;
        }

        if (elements_swapped == 0)
            break;

        knuth_gap /= 3;
        print_array(array, size);
    } while (knuth_gap > 0);
}
