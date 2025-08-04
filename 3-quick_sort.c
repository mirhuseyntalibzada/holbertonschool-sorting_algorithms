#include "sort.h"

/**
 * swap_elements - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_elements(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitions a subset of an array of integers using
 * the Lomuto partition scheme (last element as pivot).
 * @array: The full array of integers.
 * @low: The starting index of the subset to partition.
 * @high: The ending index of the subset to partition.
 * @size: The total size of the array (for printing).
 *
 * Return: The final partition index (the pivot's new index).
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_elements(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] > array[high])
	{
		swap_elements(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - Implements the Quick sort algorithm through recursion.
 * @array: The array to be sorted.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 * @size: The total size of the array (for printing).
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	quick_sort_recursive(array, 0, size - 1, size);
}
