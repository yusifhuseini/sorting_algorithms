#include "sort.h"
#include <stdio.h>

/**
 *partition - Helper function to perform the partition step of quicksort
 *@array: Array to be sorted
 *@lo: Starting index of the partition
 *@hi: Ending index of the partition
 *@size: Size of the array
 *
 *Return: Index of the pivot element after partitioning
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot = array[hi];
	i = lo - 1;
	j = lo;
	while (j < hi)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}

		j++;
	}

	if (array[hi] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = swap;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 *quicksort - Recursive function to perform the quicksort algorithm
 *@array: Array to be sorted
 *@lo: Starting index of the subarray to be sorted
 *@hi: Ending index of the subarray to be sorted
 *@size: Size of the array
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pivot;

	while (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quicksort(array, lo, pivot - 1, size);
		lo = pivot + 1; /*Updated to use while loop */
	}
}

/**
 *quick_sort - Function to initiate the quicksort algorithm on an array
 *@array: Array to be sorted
 *@size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	ssize_t lo = 0;
	ssize_t hi = size - 1;

	if (array == NULL || size < 2)
		return;

	do {
		ssize_t pivot = partition(array, lo, hi, size);

		quicksort(array, lo, pivot - 1, size);
		lo = pivot + 1;
	} while (lo < hi);
}
