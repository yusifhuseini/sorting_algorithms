#include "sort.h"
#include <stdio.h>

/**
 *bitonic_compare - Compare and swap elements in the bitonic sequence.
 *@ascending: Flag indicating whether the elements should be in ascending order
 *@array: Pointer to the array to be compared and swapped.
 *@size: Size of the array.
 */
void bitonic_compare(char ascending, int *array, size_t size)
{
	int swap;
	size_t i, distance;

	distance = size / 2;
	i = 0;

	while (i < distance)
	{
		if ((array[i] > array[i + distance]) == ascending)
		{
			swap = array[i];
			array[i] = array[i + distance];
			array[i + distance] = swap;
		}

		i++;
	}
}

/**
 *bitonic_merge - Recursively merge the bitonic sequence.
 *@ascending: Flag indicating whether the elements should be in ascending order
 *@array: Pointer to the array to be merged.
 *@size: Size of the array.
 */
void bitonic_merge(char ascending, int *array, size_t size)
{
	if (size < 2)
		return;

	bitonic_compare(ascending, array, size);
	bitonic_merge(ascending, array, size / 2);
	bitonic_merge(ascending, array + (size / 2), size / 2);
}

/**
 *bit_sort - Perform bitonic sort on an array.
 *@ascending: Flag indicating whether the elements should be in ascending order
 *@array: Pointer to the array to be sorted.
 *@size: Size of the array to be sorted.
 *@total_size: Total size of the original array.
 */
void bit_sort(char ascending, int *array, size_t size, size_t total_size)
{
	if (size < 2)
		return;

	printf("Merging[%lu/%lu] (%s):\n", size, total_size,
							(ascending == 1) ? "UP" : "DOWN");
	print_array(array, size);

	bit_sort(1, array, size / 2, total_size);
	bit_sort(0, array + (size / 2), size / 2, total_size);
	bitonic_merge(ascending, array, size);

	printf("Result[%lu/%lu] (%s):\n", size, total_size,
							(ascending == 1) ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 *bitonic_sort - Sort an array using the bitonic sort algorithm.
 *@array: Pointer to the array to be sorted.
 *@size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bit_sort(1, array, size, size);
}
