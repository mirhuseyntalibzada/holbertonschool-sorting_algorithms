#include "sort.h"

/**
 * bubble_sort - Sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm.
 * @array: array that holds integer values..
 * @size: size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
}
