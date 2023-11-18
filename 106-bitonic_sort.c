#include "sort.h"

/**
 *bitonic_merge - Merges two arrays in bitonic order
 *
 *@array: Array to be merged
 *@size: Size of the array
 *@dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	if (size > 1)
	{
		size_t k = size / 2;
		size_t i;

		for (i = 0; i < k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				int temp = array[i];

				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}

		bitonic_merge(array, k, dir);
		bitonic_merge(array + k, k, dir);
	}
}

/**
 *bitonic_sort_recursive - Recursively sorts a bitonic sequence in a specified
 *direction.
 *
 *@array: Array to be sorted
 *@size: Size of the array
 *@dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t size, int dir)
{
	if (size > 1)
	{
		size_t k = size / 2;

		printf("Merging[%lu/16] (%s):\n", size, dir ? "UP" : "DOWN");
		print_array(array, size);

		bitonic_sort_recursive(array, k, 1);
		bitonic_sort_recursive(array + k, k, 0);

		bitonic_merge(array, size, dir);

		printf("Result[%lu/16] (%s):\n", size, dir ? "UP" : "DOWN");
		print_array(array, size);
	}
}

/**
 *bitonic_sort - Sorts an array of integers in ascending order using
 *the Bitonic sort algorithm
 *
 *@array: Array to be sorted
 *@size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (size > 1)
	{
		bitonic_sort_recursive(array, size, 1);
	}
}
