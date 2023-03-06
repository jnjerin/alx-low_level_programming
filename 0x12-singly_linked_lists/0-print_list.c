#include "lists.h"

/**
 * print_list - print elements of a list
 * @h: pointer to list head
 *
 * Return: number of nodes in list
 */
size_t print_list(const list_t *h)
{
	size_t node_cnt = 0;

	/* interate through linked list, printing elements */
	while (h)
	{
		/* if string element is NULL */
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		/* assign h pointer to following node */
		h = h->next;
		node_cnt++;
	}
	/* return number of list nodes */
	return (node_cnt);
}
