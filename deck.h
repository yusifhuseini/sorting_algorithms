#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *enum kind_e - Represents the different kinds of playing cards.
 *@SPADE: Spade suit.
 *@HEART: Heart suit.
 *@CLUB: Club suit.
 *@DIAMOND: Diamond suit.
 */
typedef enum kind_e
{
	SPADE = 0,
		HEART,
		CLUB,
		DIAMOND
} kind_t;

/**
 *struct card_s - Represents a playing card.
 *@value: A pointer to a string representing the card's value.
 *@kind: The kind of the card, defined by the kind_t enum.
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 *struct deck_node_s - Represents a node in a doubly-linked list of cards.
 *@card: A pointer to the card associated with the node.
 *@prev: A pointer to the previous node in the list.
 *@next: A pointer to the next node in the list.
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /*DECK_H */
