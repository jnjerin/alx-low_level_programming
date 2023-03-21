#include "lists.h"
listint_t *add_nodeint(listint_t **head, const int n);
/**
 * insert_nodeint_at_index - insert new node at nth position
 * @head: list to add to
 * @idx: position to insert new node
 * @n: value for new node
 *
 * Return: address of new node on Success, NULL on Fail
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t new_node;
	listint_t *new = &new_node;
	listint_t *temp;
	unsigned int i = 1;

	/* return NULL, if empty list */
	if (!head)
		return (NULL);

	/* initialize temp pointer to value of head */
	temp = *head;

	/* if index is zero */
	if (!idx)
		return (add_nodeint(head, n));

	/* if idx is not zero, navigate to index */
	while (i < idx && temp)
	{
		temp = temp->next;
		i++;
	}

	if (i == idx)
	{
		/* allocate for new node */
		new = malloc(sizeof(listint_t));
		if (!new)
			return (NULL);

		/* initialize new node */
		new->n = n;

		/* point new node to old (n + 1)th node */
		new->next = temp->next;

		/* point old nth node to new node */
		temp->next = new;
	}
	else
		return (NULL);

	return (new);
}
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
