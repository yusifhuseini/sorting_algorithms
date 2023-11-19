#include "sort.h"

/**
 *bubble_sort - Sorts an array of integers in ascending order using the
 *            Bubble Sort algorithm.
 *
 *@array: The array to be sorted.
 *@size: The size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, t = size;
	int hold;

	if (array == NULL)
		return;

	for (t = size; t > 0; t--)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				/*Swap elements if they are in the wrong order */
				hold = array[i];
				array[i] = array[i + 1];
				array[i + 1] = hold;

				/*Print the array after each pass */
				print_array(array, size);
			}
		}
	}
}
