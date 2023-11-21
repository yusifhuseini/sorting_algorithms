#include "sort.h"

/**
 *swap - Swaps two elements in an array.
 *@array: The array containing the elements.
 *@idx1: Index of the first element to be swapped.
 *@idx2: Index of the second element to be swapped.
 */
void swap(int *array, unsigned int idx1, unsigned int idx2)
{
	int temp;

	temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
}

/**
 *selection_sort - Sorts array of integers using the selection sort algorithm.
 *@array: The array to be sorted.
 *@size: Number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	unsigned int outer_index = 0, inner_index, min_index;

	while (outer_index < size)
	{
		min_index = outer_index;
		inner_index = outer_index + 1;

		while (inner_index < size)
		{
			if (array[inner_index] < array[min_index])
			{
				min_index = inner_index;
			}

			inner_index++;
		}

		if (min_index != outer_index)
		{
			swap(array, outer_index, min_index);
			print_array(array, size);
		}

		outer_index++;
	}
}
