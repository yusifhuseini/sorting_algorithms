#include "sort.h"

/**
 *quick_sort_hoare - Sorts an array of integers in ascending order
 *using the Quick sort algorithm (Hoare partition scheme)
 *
 *@array: The array to be sorted
 *@size: Number of elements in the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_quick_sort(array, 0, size - 1, size);
}

/**
 *hoare_quick_sort - Recursive function to perform quick sort
 *
 *@array: The array to be sorted
 *@low: The starting index of the partition to be sorted
 *@high: The ending index of the partition to be sorted
 *@size: Number of elements in the array
 */
void hoare_quick_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = hoare_partition(array, low, high, size);

		if (pivot_index > low)
			hoare_quick_sort(array, low, pivot_index - 1, size);
		if (pivot_index < high)
			hoare_quick_sort(array, pivot_index, high, size);
	}
}

/**
 *hoare_partition - Partitions the array using the Hoare scheme
 *
 *@array: The array to be partitioned
 *@low: The starting index of the partition
 *@high: The ending index of the partition
 *@size: Number of elements in the array
 *
 *Return: Index of the pivot element after partitioning
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {	i++;
		} while (array[i] < pivot);

		do {	j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap_elements(array, i, j);
			print_array(array, size);
		}
		else
		{
			return (i);
		}
	}
}

/**
 *swap_elements - Swaps two elements in an array
 *
 *@array: The array containing elements to be swapped
 *@i: Index of the first element to be swapped
 *@j: Index of the second element to be swapped
 */
void swap_elements(int *array, int i, int j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}
