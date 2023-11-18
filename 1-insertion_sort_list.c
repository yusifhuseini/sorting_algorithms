#include "sort.h"

/**
 *insertion_sort_list - Sorts a doubly linked list of
 *integers in ascending order using Insertion sort
 *
 *@list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;

			if (current->next != NULL)
				current->next->prev = prev;
			prev->next = current->next;
			current->prev = prev->prev;
			prev->prev = current;
			current->next = prev;

			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;

			print_list(*list);
		}

		current = next;
	}
}
