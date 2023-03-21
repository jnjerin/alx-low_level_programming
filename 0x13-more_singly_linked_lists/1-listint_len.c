#include "lists.h"
/**
 * listint_len - count list elements
 * @h: list to count
 *
 * Return: number of elements on Success
 */
size_t listint_len(const listint_t *h)
{
	size_t el_cnt = 0;

	while (h)
	{
		el_cnt++;
		h = h->next;
	}
	return (el_cnt);
}
