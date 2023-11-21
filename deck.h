#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>

/**
 * enum kind_e - Represents the suits of a standard deck of cards.
 * @SPADE: Spades suit.
 * @HEART: Hearts suit.
 * @CLUB: Clubs suit.
 * @DIAMOND: Diamonds suit.
 */
typedef enum kind_e
{
	SPADE = 0,
		HEART,
		CLUB,
		DIAMOND
} kind_t;

/**
 * struct card_s - Represents a card in a standard deck.
 * @value: The value or rank of the card.
 * @kind: The suit of the card.
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Represents a node in a doubly-linked list of cards.
 * @card: Pointer to the card stored in the node.
 * @prev: Pointer to the previous node in the list.
 * @next: Pointer to the next node in the list.
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

int _strcmp(const char *str1, const char *str2);
int card_value(deck_node_t *node);
size_t list_len_deck(deck_node_t *list);
void sort_deck(deck_node_t **deck);

#endif /*DECK_H */
