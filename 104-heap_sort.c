#include "sort.h"

/**
 *sift_down - Perform the sift-down operation on a heap node.
 *
 *@array: The array to be sorted.
 *@root: Index of the root node of the heap.
 *@end: Index of the last node in the heap.
 *@size: Size of the array.
 */
void sift_down(int *array, size_t root, size_t end, size_t size)
{
	size_t left_child, right_child, swap;
	int temp;

	for (left_child = (2 * root) + 1; left_child <= end;
								left_child = (2 * root) + 1)
	{
		swap = root;
		right_child = left_child + 1;

		if (array[swap] < array[left_child])
			swap = left_child;
		if (right_child <= end && array[swap] < array[right_child])
			swap = right_child;
		if (swap == root)
			return;

		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;

		print_array(array, size);
		root = swap;
	}
}

/**
 *make_heap - Build a max heap from the array.
 *
 *@array: The array to be sorted.
 *@size: Size of the array.
 */
void make_heap(int *array, size_t size)
{
	size_t parent;

	parent = ((size - 1) - 1) / 2;

	while (1)
	{
		sift_down(array, parent, size - 1, size);

		if (parent == 0)
			break;

		parent--;
	}
}

/**
 *heap_sort - Perform the heap sort algorithm on the array.
 *
 *@array: The array to be sorted.
 *@size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	if (array == NULL || size < 2)
		return;

	make_heap(array, size);

	for (end = size - 1; end > 0; end--)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;

		print_array(array, size);

		sift_down(array, 0, end - 1, size);
	}
}
