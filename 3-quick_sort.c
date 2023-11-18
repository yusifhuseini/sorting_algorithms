#include "sort.h"

/**
 *lomuto_partition - Lomuto partition scheme for quicksort
 *@array: The array to be sorted
 *@low: Starting index of the partition
 *@high: Ending index of the partition
 *@size: Size of the array
 *
 *Return: Index of the pivot element after partition
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot, temp;
	ssize_t i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			if (i != j)
			{
				print_array(array, size);
			}
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	if (i + 1 != high)
	{
		print_array(array, size);
	}

	return (i + 1);
}

/**
 *quicksort - Recursive function to implement quicksort
 *@array: The array to be sorted
 *@low: Starting index of the array or partition
 *@high: Ending index of the array or partition
 *@size: Size of the array
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high, size);

		quicksort(array, low, partition_index - 1, size);
		quicksort(array, partition_index + 1, high, size);
	}
}

/**
 *quick_sort - Sorts an array of integers in ascending order using Quick sort
 *@array: The array to be sorted
 *@size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
