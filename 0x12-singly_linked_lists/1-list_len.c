#include "lists.h"
/**
 * list_len - parse list to count elements
 * @h: linked list to parse
 *
 * Return: number of elements in list
 */
size_t list_len(const list_t *h)
{
	size_t el_cnt = 0;

	while (h)
	{
		el_cnt++;
		h = h->next;
	}
	return (el_cnt);
}
