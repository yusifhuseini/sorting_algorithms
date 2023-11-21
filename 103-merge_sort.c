#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *merge - Merges two halves of an array.
 *@start: Starting index of the first half.
 *@middle: Ending index of the first half and starting index of the second half
 *@end: Ending index of the second half.
 *@dest: The dest array where the merged elements will be stored.
 *@source: The source array to be merged.
 */
void merge(size_t start, size_t middle, size_t end, int *dest, int *source)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);

	i = start;
	j = middle;
	k = start;

	/*Merge the two halves */
	while (k < end)
	{
		if (i < middle && (j >= end || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}

		k++;
	}

	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
 *split_and_merge - Recursively splits and merges the array.
 *@start: Starting index of the subarray.
 *@end: Ending index of the subarray.
 *@array: The array to be sorted.
 *@copy: Temporary array for merging.
 */
void split_and_merge(size_t start, size_t end, int *array, int *copy)
{
	size_t middle;

	/*Base case: If the subarray has 1 or 0 elements, it is already sorted */
	if (end - start < 2)
		return;

	middle = (start + end) / 2;

	/*Recursively split and merge the left and right halves */
	split_and_merge(start, middle, array, copy);
	split_and_merge(middle, end, array, copy);

	/*Merge the two sorted halves */
	merge(start, middle, end, array, copy);

	for (middle = start; middle < end; middle++)
		copy[middle] = array[middle];
}

/**
 *merge_sort - Sorts an array using the merge sort algorithm.
 *@array: The array to be sorted.
 *@size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *copy;

	/*Check if array is NULL or has less than 2 elements */
	if (array == NULL || size < 2)
		return;

	/*Allocate memory for a temporary array */
	copy = malloc(sizeof(int) * size);

	/*Check if memory allocation was successful */
	if (copy == NULL)
		return;

	i = 0;

	/*Copy elements from array to the temporary array */
	do {
		copy[i] = array[i];
		i++;
	} while (i < size);

	/*Perform the merge sort algorithm */
	split_and_merge(0, size, array, copy);

	/*Free the allocated memory */
	free(copy);
}
