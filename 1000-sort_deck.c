#include "deck.h"

/**
 *sort_deck - Sorts a deck of cards in ascending order based on their values.
 *
 *@deck: A pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck)
{
	size_t len;
	deck_node_t *curr, *one, *two, *three, *four;

	len = list_len_deck(*deck);

	/*Check if the deck is empty or has only one card */
	if (!deck || !*deck || len < 2)
		return;

	/*Bubble sort algorithm to sort the deck */
	for (curr = *deck; curr; curr = curr->next)
	{
		if (curr->prev && card_value(curr) < card_value(curr->prev))
		{
		    /*Swapping cards */
			one = curr->prev->prev;
			two = curr->prev;
			three = curr;
			four = curr->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*deck = three;
			two->prev = three;
			curr = *deck; /*Resetting the current pointer */
		}
	}
}

/**
 *card_value - Returns the numeric value of a card.
 *
 *@node: A pointer to the deck_node_t structure representing the card.
 *
 *Return: The numeric value of the card.
 */
int card_value(deck_node_t *node)
{
	int i, kind_val = 0;
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	char *val[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};

	/*Determine the rank value */
	for (i = 1; i <= 13; i++)
	{
		if (!_strcmp(node->card->value, val[i - 1]))
			kind_val = i;
	}

	/*Determine the suit value */
	for (i = 1; i <= 4; i++)
	{
		if (!_strcmp(kinds[node->card->kind], kinds[i - 1]))
			kind_val = kind_val + (13 * i);
	}

	return (kind_val);
}

/**
 *_strcmp - Compares two strings lexicographically.
 *
 *@str1: The first string.
 *@str2: The second string.
 *
 *Return: An integer greater than, equal to, or less than 0, according to
 *        the first string is greater than, equal to, or less than the second.
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
 *list_len_deck - Returns the length of a linked list of a deck of cards.
 *
 *@list: A pointer to the head of the deck.
 *
 *Return: The number of cards in the deck.
 */
size_t list_len_deck(deck_node_t *list)
{
	size_t len = 0;

	/*Count the number of nodes in the linked list */
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
