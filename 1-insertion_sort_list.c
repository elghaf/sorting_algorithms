#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascend.
 * order list using the algo Sort algorithm.
 * @list: A pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current_node, *iteration_node, *temp_node;

    if (list == NULL || *list == NULL)
        return;

    iteration_node = (*list)->next;

    while (iteration_node)
    {
        current_node = iteration_node;
        while (current_node->prev != NULL && current_node->prev->n > current_node->n)
        {
            temp_node = current_node->prev;
            current_node->prev = temp_node->prev;
            temp_node->next = current_node->next;

            if (temp_node->next != NULL)
                temp_node->next->prev = temp_node;

            if (current_node->prev != NULL)
                current_node->prev->next = current_node;
            else
            {
                *list = current_node;
                current_node->prev = NULL;
            }

            current_node->next = temp_node;
            temp_node->prev = current_node;

            print_list(*list);
        }
        iteration_node = iteration_node->next;
    }
}
