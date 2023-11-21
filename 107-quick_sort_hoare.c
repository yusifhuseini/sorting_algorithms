#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *partition - Lomuto partition scheme for quicksort
 *@array: Array to be partitioned
 *@low: Starting index of the partition
 *@high: Ending index of the partition
 *@size: Size of the array
 *
 *Return: Index of the partition
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int temp, pivot;
	ssize_t i;

	pivot = array[high];
	for (i = low; i <= high;)
	{
		/*Find element on the left side that should be on the right */
		for (; array[i] < pivot; i++)
		;
		/*Find element on the right side that should be on the left */
		for (; array[high] > pivot; high--)
		;
		/*Swap elements if needed */
		if (i <= high)
		{
			if (i != high)
			{
				temp = array[i];
				array[i] = array[high];
				array[high] = temp;

				/*Print the array after swapping */
				print_array(array, size);
			}

			i++;
			high--;
		}
	}

	return (high);
}

/**
 *quicksort - Recursive function to perform quicksort
 *@array: Array to be sorted
 *@low: Starting index of the array/subarray
 *@high: Ending index of the array/subarray
 *@size: Size of the array
 *
 *Return: void
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		/*Get the partition index */
		pivot = partition(array, low, high, size);

		/*Recursively sort the subarrays */
		quicksort(array, low, pivot, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 *quick_sort_hoare - Wrapper function for quicksort using Hoare's partition
 *@array: Array to be sorted
 *@size: Size of the array
 *
 *Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/*Call the quicksort function */
	quicksort(array, 0, size - 1, size);
}
