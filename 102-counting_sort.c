#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order.
 * using the Counting sort algorithm
 * @array: pointer to array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    int max = 0;
    size_t i;

    for (i = 0; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    int *count_array = calloc(max + 1, sizeof(int));
    if (!count_array)
        return;

    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    for (i = 1; i <= (size_t)max; i++)
        count_array[i] += count_array[i - 1];

    int *aux = malloc(size * sizeof(int));
    if (!aux) {
        free(count_array);
        return;
    }

    i = size - 1;
    do {
        aux[--count_array[array[i]]] = array[i];
    } while (i-- != 0);

    for (i = 0; i < size; i++)
        array[i] = aux[i];

    free(aux);
    free(count_array);
}
