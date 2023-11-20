#include "sort.h"

/**
 *swap_nodes - swap the nodes themselves.
 *@node1: pointer.
 *@node2: pointer.
 *@list: doubly linked list
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	listint_t *temp1 = node1->next;
	listint_t *temp2 = node2->prev;

	if (temp1 != NULL)
		temp1->prev = node2;
	if (temp2 != NULL)
		temp2->next = node1;

	node1->prev = temp2;
	node2->next = temp1;
	node1->next = node2;
	node2->prev = node1;

	if (*list == node2)
		*list = node1;

	print_list(*list);
}

/**
 *cocktail_sort_list - cocktail_sort_list
 *
 *@list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *check = *list, *first = NULL, *last = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	do {
		while (check->next)
		{
			if (check->n > check->next->n)
				swap_nodes(check->next, check, list);
			else
				check = check->next;
		}

		last = check;
		while (check->prev != first)
		{
			if (check->n < check->prev->n)
				swap_nodes(check, check->prev, list);
			else
				check = check->prev;
		}

		first = check;
	} while (first != last);
}
