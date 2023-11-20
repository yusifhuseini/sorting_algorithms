#include "deck.h"

/**
 *compare_cards - Compare two cards for sorting
 *@a: First card
 *@b: Second card
 *Return: Integer less than, equal to, or greater than zero if a is found,
 *respectively, to be less than, to match, or be greater than b.
 */
int compare_cards(const void *a, const void *b)
{
	const deck_node_t *node_a = *(const deck_node_t **) a;
	const deck_node_t *node_b = *(const deck_node_t **) b;

	if (node_a->card->kind != node_b->card->kind)
		return (node_a->card->kind - node_b->card->kind);
	return (strcmp(node_a->card->value, node_b->card->value));
}

/**
 *sort_deck - Sorts a deck of cards
 *@deck: Pointer to the deck to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	size_t i;
	deck_node_t **array;
	deck_node_t *current;

	if (!deck || !*deck || !(*deck)->next)
		return;

	current = *deck;

	/*Create an array of deck nodes */
	array = malloc(sizeof(deck_node_t *) * 52);
	if (!array)
		return;

	for (i = 0; i < 52 && current; ++i)
	{
		array[i] = current;
		current = current->next;
	}

	/*Sort the array of deck nodes */
	qsort(array, i, sizeof(deck_node_t *), compare_cards);

	/*Update the deck with the sorted nodes */
	*deck = array[0];
	for (i = 0; i < 52 - 1; ++i)
	{
		array[i]->next = array[i + 1];
		array[i + 1]->prev = array[i];
	}

	array[51]->next = NULL;
	free(array);
}
