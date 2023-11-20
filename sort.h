#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *struct listint_s - Doubly linked list node
 *
 *@n: Integer stored in the node
 *@prev: Pointer to the previous element of the list
 *@next: Pointer to the next element of the list
 */
typedef struct listint_s
{
        const int n;
        struct listint_s *prev;
        struct listint_s *next;
} listint_t;

/**
 *struct deck_node_s - Doubly linked list node for a card deck
 *
 *@card: Integer value of the card (0-52)
 *@prev: Pointer to the previous node in the deck
 *@next: Pointer to the next node in the deck
 */
typedef struct deck_node_s
{
        int card;
        struct deck_node_s *prev;
        struct deck_node_s *next;
} deck_node_t;

/*Function prototypes */
int getMax(int *array, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);
void bitonic_sort(int *array, size_t size);
/* void bubble_sort(int *array, size_t size); */
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void countingSort(int *array, size_t size, int exp);
void heap_sort(int *array, size_t size);
void hoare_quick_sort(int *array, int low, int high, size_t size);
void insertion_sort_list(listint_t **list);
void merge(int *array, size_t size, int *left, size_t left_size,
int *right, size_t right_size);
void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void quick_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void radix_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void sort_deck(deck_node_t **deck);
void sort_deck(deck_node_t **deck);
void swap_elements(int *array, int i, int j);
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list);









void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /*SORT_H */
