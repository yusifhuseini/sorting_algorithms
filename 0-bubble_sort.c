#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 *               Bubble Sort algorithm.
 *
 * @array: Pointer to the first element of the array to be sorted.
 * @size: Size of the array.
 *
 * Description:
 * - This function implements the Bubble Sort algorithm to sort the given
 *   array in ascending order.
 * - It compares adjacent elements and swaps them if they are in the wrong
 *   order until the entire array is sorted.
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, n = size;
	int new, temp;

	while (n >= 1)
	{
		/* Swap elements and update the position of the last swap */
		new = 0;

		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				new = i;
				/* Print the current state of the array */
				print_array(array, size);
			}
		}

		/* Update the loop condition variable */
		n = new;
	}
}
