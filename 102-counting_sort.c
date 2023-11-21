#include "sort.h"
#include "stdlib.h"

/**
 *counting_sort - Sorts an array of integers in ascending order
 *using the counting sort algorithm.
 *
 *@array: The array to be sorted.
 *@size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int i, max_value;
	int *count_array = NULL, *temp_array = NULL;
	size_t j, original_value, cumulative_count = 0;

	if (array == NULL || size < 2)
		return;
	temp_array = malloc(sizeof(int) * size);
	if (temp_array == NULL)
		return;
	for (j = 0, max_value = 0; j < size; j++)
	{
		temp_array[j] = array[j];
		if (array[j] > max_value)
			max_value = array[j];
	}
	count_array = malloc(sizeof(int) * (max_value + 1));
	if (count_array == NULL)
	{
		free(temp_array);
		return;
	}
	for (i = 0; i <= max_value; i++)
		count_array[i] = 0;
	for (j = 0; j < size; j++)
		count_array[array[j]] += 1;
	for (i = 0; i <= max_value; i++)
	{
		original_value = count_array[i];
		count_array[i] = cumulative_count;
		cumulative_count += original_value;
	}
	for (j = 0; j < size; j++)
	{
		array[count_array[temp_array[j]]] = temp_array[j];
		count_array[temp_array[j]] += 1;
	}
	print_array(count_array, max_value + 1);
	/*Free allocated memory */
	free(count_array);
	free(temp_array);
}
