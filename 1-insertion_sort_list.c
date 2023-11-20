#include "sort.h"

/**
 *insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Insertion Sort algorithm.
 *
 *@list: A pointer to a pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *temp, *next, *temp_next, *temp_prev;
	int i;

	/* Check if the list or its next element is NULL */
	if (list == NULL || (*list)->next == NULL)
		return;

	for (node = (*list)->next; node != NULL; node = next)
	{
		do {	temp = node;
			next = node->next;
			temp_next = temp->next;
			temp_prev = temp->prev;

			for (i = 0; temp->prev != NULL && temp_prev->n > temp->n; i++)
			{	/* Adjust pointers to perform the swap */
				if (temp_next != NULL)
					temp_next->prev = temp_prev;
				temp_prev->next = temp_next;

				if (temp_prev->prev == NULL)
				{		/* Update head if the node is moved to the beginning */
					temp_prev->prev = temp;
					*list = temp;
					temp->prev = NULL;
				}
				else
				{		/* Connect nodes when the node is inserted in the middle */
					temp->prev = temp_prev->prev;
					temp_prev->prev->next = temp;
					temp_prev->prev = temp;
				}
				temp->next = temp_prev;
				temp_prev = temp->prev;
				temp_next = temp->next;

				print_list(*list); /* Print the updated list after each iteration */
			}
		} while (i > 0);
	}
}
