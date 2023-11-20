#include "sort.h"

/**
 *heapify - Helper function to perform heapify operation on the array
 *
 *@array: The array to be sorted
 *@size: The size of the array
 *@i: Index of the root of the subtree to be heapified
 *@n: Size of the array for printing
 */
void heapify(int *array, size_t size, size_t i, size_t n)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		/*Swap array[i] and array[largest] */
		int temp = array[i];

		array[i] = array[largest];
		array[largest] = temp;

		print_array(array, n);

		/*Recursively heapify the affected sub-tree */
		heapify(array, size, largest, n);
	}
}

/**
 *heap_sort - Sorts an array of integers in ascending order using Heap sort
 *
 *@array: The array to be sorted
 *@size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	/*Build heap (rearrange array) */
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	/*One by one extract an element from the heap */
	for (i = size - 1; i > 0; i--)
	{
		/*Move the current root to the end */
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);

		/*Call max heapify on the reduced heap */
		heapify(array, i, 0, size);
	}
}
