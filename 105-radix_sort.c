#include "sort.h"
#include <stdlib.h>

/**
 * power_of_10 - Compute the power of 10 for a given exponent.
 * @power: The exponent for the power of 10.
 *
 * Return: The result of 10 raised to the power
 */
unsigned int power_of_10(unsigned int power)
{
	unsigned int i, result;

	result = 1;
	i = 0;
	while (i < power)
	{
		result *= 10;
		i++;
	}

	return (result);
}

/**
 * count_sort - sorts Perform counting sort based on a specific digit place.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @digit: The digit place to consider for sorting.
 *
 * Return: 1 if sorting is performed, 0 otherwise.
 */
unsigned int count_sort(int *array, size_t size, unsigned int digit)
{
	int count[10] = { 0 };

	int i, *copy = NULL;
	size_t j, temp, total = 0;
	unsigned int divisor1, divisor2, sort = 0;

	divisor2 = power_of_10(digit - 1);
	divisor1 = divisor2 * 10;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		exit(1);
	/*Copy the array to 'copy' array */
	for (j = 0; j < size; j++)
	{
		copy[j] = array[j];
		if (array[j] / divisor1 != 0)
			sort = 1;
	}

	/*Initialize count array to 0 using a for loop */
	for (i = 0; i < 10; i++)
		count[i] = 0;
	/*Count occurrences of each digit using a for loop */
	for (j = 0; j < size; j++)
		count[(array[j] % divisor1) / divisor2] += 1;
	/*Update count array with cumulative counts using a for loop */
	for (i = 0; i < 10; i++)
	{
		temp = count[i];
		count[i] = total;
		total += temp;
	}
	/*Update the original array using count array &'copy' array using for loop */
	for (j = 0; j < size; j++)
	{
		array[count[(copy[j] % divisor1) / divisor2]] = copy[j];
		count[(copy[j] % divisor1) / divisor2] += 1;
	}
	free(copy); /*Free dynamically allocated memory */
	return (sort);
}

/**
 * radix_sort - Perform radix sort on an array.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	unsigned int i = 1, sort = 1;

	if (array == NULL || size < 2)
		return;
	do {
		sort = count_sort(array, size, i);
		print_array(array, size);
		i++;
	} while (sort == 1);
}
