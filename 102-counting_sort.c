#include "sort.h"

/**
 *counting_sort - sorts an array with the Counting sort algorithm
 *@array: array to sort
 *@size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max_value = array[0];
	int current_value;
	int *count_array, *output_array;

	if (size < 2 || !array)
		return;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	count_array = malloc(sizeof(int) * (max_value + 1));
	output_array = malloc(sizeof(int) * size);

	for (i = 0; i <= (size_t) max_value; i++)
		count_array[i] = 0;

	for (i = 0; i < size; i++)
	{
		current_value = array[i];
		count_array[current_value]++;
	}

	for (i = 1; i <= (size_t) max_value; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, max_value + 1);

	for (i = size - 1; i < size; i--)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output_array[i];
	free(output_array);
	free(count_array);
}
