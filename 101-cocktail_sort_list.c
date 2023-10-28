#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the list
 * @a: first node
 * @b: second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
    if (a->prev)
        a->prev->next = b;
    else
        *list = b;

    if (b->next)
        b->next->prev = a;

    a->next = b->next;
    b->prev = a->prev;
    b->next = a;
    a->prev = b;

    print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail sort algorithm
 * @list: pointer to the list head
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *current;
    int swapped = 0;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        current = *list;

        while (current->next != NULL) {
            if (current->n > current->next->n) {
                swap_nodes(list, current, current->next);
                swapped = 1;
            } else {
                current = current->next;
            }
        }

        if (swapped == 0)
            break;

        swapped = 0;

        while (current->prev != NULL) {
            if (current->prev->n > current->n) {
                swap_nodes(list, current->prev, current);
                swapped = 1;
            } else {
                current = current->prev;
            }
        }

    } while (swapped);
}
