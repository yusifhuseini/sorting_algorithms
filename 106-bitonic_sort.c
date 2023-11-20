#include "sort.h"
#include <stdio.h>

/**
 * bitonic_compare - Perform bitonic comparison and swap elements if needed
 * @up: 1 for ascending order, 0 for descending order
 * @array: Array to be compared and swapped
 * @size: Size of the array
 */
void bitonic_compare(char up, int *array, size_t size)
{
	int swap;
	size_t i, distance;

	/* Calculate the distance for comparison */
	distance = size / 2;

	/* Perform bitonic comparison */
	for (i = 0; i < distance; i++)
	{
		/* Check if swapping is needed based on the bitonic comparison */
		if ((array[i] > array[i + distance]) == up)
		{
			/* Swap elements if the condition is true */
			swap = array[i];
			array[i] = array[i + distance];
			array[i + distance] = swap;
		}
	}
}

/**
 * bitonic_merge - Recursively apply bitonic merge to the array
 * @up: 1 for ascending order, 0 for descending order
 * @array: Array to be merged
 * @size: Size of the array
 */
void bitonic_merge(char up, int *array, size_t size)
{
	/* Base case: If the size is less than 2, return */
	if (size < 2)
		return;

	/* Perform bitonic comparison */
	bitonic_compare(up, array, size);

	/* Recursively apply bitonic merge to the first half */
	bitonic_merge(up, array, size / 2);

	/* Recursively apply bitonic merge to the second half */
	bitonic_merge(up, array + (size / 2), size / 2);
}

/**
 * bit_sort - Perform bitonic sort on the array
 * @up: 1 for ascending order, 0 for descending order
 * @array: Array to be sorted
 * @size: Size of the array
 * @t: Parameter for printing information about the merging process
 */
void bit_sort(char up, int *array, size_t size, size_t t)
{
	/* Base case: If the size is less than 2, return */
	if (size < 2)
		return;

	/* Print information about the merging process */
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

	/* Recursively apply bit_sort to the first half */
	bit_sort(1, array, size / 2, t);

	/* Recursively apply bit_sort to the second half */
	bit_sort(0, array + (size / 2), size / 2, t);

	/* Merge the two sorted halves */
	bitonic_merge(up, array, size);

	/* Print the result of the merging process */
	printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * bitonic_sort - Start the bitonic sort process
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	/* Base case: If the array is NULL or size is less than 2, return */
	if (array == NULL || size < 2)
		return;

	/* Start the bitonic sort process */
	bit_sort(1, array, size, size);
}
