#include "sort.h"
/**
 * swap - Swap two nodes in a listint_t doubly-linked list.
 * @a: address of first node.
 * @c: adress of second node.
 * Return: void.
 */
void swap(listint_t *a, listint_t *c)
{
	if (a->prev)
		a->prev->next = c;
	if (c->next)
		c->next->prev = a;

	a->next = c->next;
	c->prev = a->prev;
	a->prev = c;
	c->next = a;
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *x, *y;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	x = (*list)->next;
	while (x)
	{
		y = x;
		x = x->next;
		while (y && y->prev)
		{
			if (y->prev->n > y->n)
			{
				swap(y->prev, y);
				if (!y->prev)
					*list = y;
				print_list((const listint_t *)*list);
			}
			else
				y = y->prev;
		}
	}
}
