#include "sort.h"

/**
 *bubble_sort - Sorts an array of integers in ascending order using the
 *           Bubble Sort algorithm.
 *
 *@array: The array to be sorted.
 *@size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t index;
	size_t tmp = 0;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
		for (index = 0; index < size; index++)
		{
			if (array[index] > array[index + 1] && array[index + 1])
			{
				tmp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = tmp;
				print_array(array, size);
			}
		}
}
