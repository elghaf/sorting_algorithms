/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: an array of integers to sort
 * @size: the size of array
 */

void selection_sort(int *array, size_t size)
{
    size_t current_index, compare_index, min_index;
    int *temp; // Pointer to temporarily store the element being swapped

    for (current_index = 0; current_index < size - 1; current_index++)
    {
        min_index = current_index;
        for (compare_index = current_index + 1; compare_index < size; compare_index++)
        {
            if (array[compare_index] < array[min_index])
                min_index = compare_index;
        }

        if (min_index != current_index)
        {
            // Swap the elements using a pointer
            temp = &array[current_index];
            array[current_index] = array[min_index];
            array[min_index] = *temp;
            print_array(array, size);
        }
    }
}
