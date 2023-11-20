#include "sort.h"
#include <stdio.h>

/**
 *bitonic_compare - Perform bitonic comparison and swap elements if needed
 *@up: 1 for ascending order, 0 for descending order
 *@array: Array to be compared and swapped
 *@size: Size of the array
 */
void bitonic_compare(char up, int *array, size_t size)
{
	size_t i, dist;
	int swap;

	dist = size / 2;
	for (i = 0; i < dist; i++)
	{
		if ((array[i] > array[i + dist]) == up)
		{
			swap = array[i];
			array[i] = array[i + dist];
			array[i + dist] = swap;
		}
	}
}

/**
 *bitonic_merge - Recursively apply bitonic merge to the array
 *@up: 1 for ascending order, 0 for descending order
 *@array: Array to be merged
 *@size: Size of the array
 */
void bitonic_merge(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	bitonic_compare(up, array, size);
	bitonic_merge(up, array, size / 2);
	bitonic_merge(up, array + (size / 2), size / 2);
}

/**
 *bit_sort - Perform bitonic sort on the array
 *@up: 1 for ascending order, 0 for descending order
 *@array: Array to be sorted
 *@size: Size of the array
 *@t: Parameter for printing information about the merging process
 */
void bit_sort(char up, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging[%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	bit_sort(1, array, size / 2, t);
	bit_sort(0, array + (size / 2), size / 2, t);
	bitonic_merge(up, array, size);
	printf("Result[%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 *bitonic_sort - Start the bitonic sort process
 *@array: Array to be sorted
 *@size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sort(1, array, size, size);
}
