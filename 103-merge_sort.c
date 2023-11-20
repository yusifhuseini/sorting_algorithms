#include "sort.h"

/**
 *merge_sort - Sorts an array of integers in ascending order using Merge sort
 *
 *@array: The array to be sorted
 *@size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	/*Declare variables at the beginning of the block */
	size_t mid, left_size, right_size;
	int *left, *right;

	if (size < 2)
		return;

	mid = size / 2;
	left_size = mid;
	right_size = size - mid;

	left = array;
	right = array + mid;

	/*Recursive calls to sort the left and right subarrays */
	merge_sort(left, left_size);
	merge_sort(right, right_size);

	/*Merge the sorted left and right subarrays */
	merge(array, size, left, left_size, right, right_size);
}

/**
 *merge - Merges two sorted subarrays into a single sorted array
 *
 *@array: The array to be merged
 *@size: Number of elements in the array
 *@left: The left subarray
 *@left_size: Number of elements in the left subarray
 *@right: The right subarray
 *@right_size: Number of elements in the right subarray
 */
void merge(int *array, size_t size, int *left,
				size_t left_size, int *right, size_t right_size)
{
	size_t i, j, k;
	int *merged = malloc(size * sizeof(int));

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
	i = j = k = 0;
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			merged[k] = left[i];
			i++;
		}
		else
		{
			merged[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left_size)
	{
		merged[k] = left[i];
		i++;
		k++;
	}
	while (j < right_size)
	{
		merged[k] = right[j];
		j++;
		k++;
	}
	for (i = 0; i < size; i++)
		array[i] = merged[i];
	printf("[Done]: ");
	print_array(merged, size);
	free(merged);
}
