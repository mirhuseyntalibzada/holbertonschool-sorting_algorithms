#include "sort.h"

void print_list(const listint_t *list)
{
	while (list != NULL)
	{
		if (list->next == NULL)
		{
			printf("%d\n", list->n);
		}
		else
		{
			printf("%d, ", list->n);
		}
		list = list->next;
	}
}
