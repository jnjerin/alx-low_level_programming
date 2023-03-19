#include "lists.h"
/**
 * add_nodeint - add new node to beginning of list
 * @head: pointer to list head
 * @n: value to initialize in new node
 *
 * Return: address of new node on Success, NULL on Fail
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t node; /* new node */
	listint_t *new = &node; /* pointer to new node */

	/* check for NULL head */
	if (!head)
		return (NULL);

	/* allocate for new node */
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	/* initialize new node */
	new->n = n;
	new->next = *head; /* point new head to old head */

	/* assign head pointer to new head */
	*head = new;

	return (new);
}
