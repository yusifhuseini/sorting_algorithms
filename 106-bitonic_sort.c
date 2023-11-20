#include "sort.h"
#include <stdio.h>

/**
 *swap_elements - Swaps the values of two elements.
 *
 *@element1: Pointer to the first element.
 *@element2: Pointer to the second element.
 */
void swap_elements(int *element1, int *element2)
{
	int temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}

/**
 *bitonic_compare - Compares and swaps elements in a bitonic sequence.
 *
 *@isAscending: Flag indicating the sorting order.
 *@array: Pointer to the array.
 *@size: Size of the array.
 */
void bitonic_compare(char isAscending, int *array, size_t size)
{
	size_t i, distance;

	distance = size / 2;
	i = 0;

	while (i < distance)
	{
		if ((array[i] > array[i + distance]) == isAscending)
		{
			swap_elements(&array[i], &array[i + distance]);
		}

		i++;
	}
}

/**
 *bitonic_merge - Recursively performs bitonic merge on an array.
 *
 *@isAscending: Flag indicating the sorting order.
 *@array: Pointer to the array.
 *@size: Size of the array.
 */
void bitonic_merge(char isAscending, int *array, size_t size)
{
	if (size < 2)
		return;

	bitonic_compare(isAscending, array, size);
	bitonic_merge(isAscending, array, size / 2);
	bitonic_merge(isAscending, array + (size / 2), size / 2);
}

/**
 *bit_sort - Recursively performs bitonic sort on an array.
 *
 *@isAscending: Flag indicating the sorting order.
 *@array: Pointer to the array.
 *@size: Size of the array.
 *@t: Total size of the original array.
 */
void bit_sort(char isAscending, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;

	printf("Merging[%lu/%lu] (%s):\n", size, t,
							(isAscending == 1) ? "UP" : "DOWN");
	print_array(array, size);

	bit_sort(1, array, size / 2, t);
	bit_sort(0, array + (size / 2), size / 2, t);

	bitonic_merge(isAscending, array, size);

	printf("Result[%lu/%lu] (%s):\n", size, t,
							(isAscending == 1) ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 *bitonic_sort - Sorts an array using bitonic sort algorithm.
 *
 *@array: Pointer to the array.
 *@size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bit_sort(1, array, size, size);
}
