#include "sort.h"

void print_array(int *array, size_t size)
{
	size_t i = 0;
	while (i < size)
	{
		if ((size - 1) == i)
		{
			printf("%d", array[i]);
		}
		else
		{
			printf("%d, ", array[i]);
		}
		i++;
	}

	printf("\n");
}
