#include "deck.h"

/**
 *sort_deck - Sorts a deck of cards in ascending order based on card values.
 *@deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t deck_length;
	deck_node_t *current, *prev_two, *prev_one, *current_next;
	deck_node_t *curr;

	deck_length = list_length_deck(*deck);

	if (!deck || !*deck || deck_length < 2)
		return;

	for (curr = *deck; curr != NULL; curr = curr->next)
	{
		if (curr->prev && card_value(curr) < card_value(curr->prev))
		{
			prev_two = curr->prev->prev;
			prev_one = curr->prev;
			current = curr;
			current_next = curr->next;

			prev_one->next = current_next;
			if (current_next)
				current_next->prev = prev_one;
			current->next = prev_one;
			current->prev = prev_two;
			if (prev_two)
				prev_two->next = current;
			else
				*deck = current;
			prev_one->prev = current;
			curr = *deck;
		}
	}
}

/**
 *card_value - Calculates the value of a card in the deck.
 *@node: Pointer to the node containing the card
 *
 *Return: The calculated value of the card.
 */
int card_value(deck_node_t *node)
{
	char *card_values[13] = { "Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King" };

	char *card_suits[4] = { "SPADE", "HEART", "CLUB", "DIAMOND" };

	int i, value = 0;

	i = 1;
	while (i <= 13 && _strcmp(node->card->value, card_values[i - 1]) != 0)
	{
		value = i;
		i++;
	}

	i = 1;
	while (i <= 4 && _strcmp(card_suits[node->card->kind],
								card_suits[i - 1]) != 0)
	{
		value = value + (13 * i);
		i++;
	}

	return (value);
}

/**
 *_strcmp - Compares two strings.
 *@str1: First string
 *@str2: Second string
 *
 *Return: 0 if strings are equal, positive if str1 is greater,
 *negative if str2 is greater
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return (0);
		}

		str1++;
		str2++;
	}

	return (*str1 - *str2);
}

/**
 *list_length_deck - Calculates the length of a deck.
 *@list: Pointer to the head of the deck
 *
 *Return: The length of the deck.
 */
size_t list_length_deck(deck_node_t *list)
{
	size_t length = 0;

	while (list)
	{
		length++;
		list = list->next;
	}

	return (length);
}
