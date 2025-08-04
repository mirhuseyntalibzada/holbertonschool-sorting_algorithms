#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order
 * using the Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_ptr, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insertion_ptr = current;
		current = current->next;

		while (insertion_ptr->prev != NULL && insertion_ptr->n < insertion_ptr->prev->n)
		{
			tmp = insertion_ptr->prev;

			tmp->next = insertion_ptr->next;
			if (insertion_ptr->next != NULL)
			{
				insertion_ptr->next->prev = tmp;
			}

			insertion_ptr->prev = tmp->prev;
			insertion_ptr->next = tmp;

			if (tmp->prev != NULL)
			{
				tmp->prev->next = insertion_ptr;
			}
			else
			{
				*list = insertion_ptr;
			}
			tmp->prev = insertion_ptr;

			print_list(*list);
		}
	}
}
