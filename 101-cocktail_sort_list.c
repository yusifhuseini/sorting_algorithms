#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 * @current_node: Pointer to the current node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *current_node)
{
	/* Update pointers to perform the swap */
	current_node->next->prev = current_node->prev;
	if (current_node->prev)
		current_node->prev->next = current_node->next;
	else
		*list = current_node->next;

	current_node->prev = current_node->next;
	current_node->next = current_node->next->next;
	current_node->prev->next = current_node;

	if (current_node->next)
		current_node->next->prev = current_node;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using
 * the Cocktail Shaker sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	char has_swapped = 1;
	listint_t *current_node;

	if (list == NULL || *list == NULL)
		return;

	current_node = *list;

	while (has_swapped != 0)
	{
		has_swapped = 0;

		while (current_node->next != NULL)
		{
			/* Check if adjacent nodes need to be swapped */
			if (current_node->next->n < current_node->n)
			{
				swap_nodes(list, current_node);
				has_swapped = 1;
				print_list(*list);
			}
			else
				current_node = current_node->next;
		}
		if (has_swapped == 0)
			break;
		has_swapped = 0;
		while (current_node->prev != NULL)
		{
			/* Check if adjacent nodes need to be swapped in the opposite direction */
			if (current_node->prev->n > current_node->n)
			{
				swap_nodes(list, current_node->prev);
				has_swapped = 1;
				print_list(*list);
			}
			else
				current_node = current_node->prev;
		}
	}
}

