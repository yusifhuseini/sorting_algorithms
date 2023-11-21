#include "sort.h"

/**
 *shell_sort - Sorts an array of integers in ascending order using
 *Shell sort (Knuth sequence)
 *
 *@array: The array to be sorted
 *@size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate initial gap using Knuth's formula */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Perform Shell Sort */
	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = temp;
		}
		/* Display the array after each gap iteration */
		print_array(array, size);
	}
}
