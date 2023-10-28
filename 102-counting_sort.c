#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: pointer to array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{

    int *aux;
    int max = 0;
    size_t i;

    if (!array || size < 2)
        return;

    for (i = 0; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    int *count_array;
    count_array = calloc(max + 1, sizeof(int));
    if (!count_array)
        return;

    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    aux = malloc(size * sizeof(int));
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
