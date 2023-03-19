#include "lists.h"
/**
 * add_nodeint_end - add new node to list end
 * @head: pointer to list head
 * @n: value to initialize
 *
 * Return: address of new node on Success, NULL on Fail
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t node;
	listint_t *new = &node;
	listint_t *temp;

	/* check if head pointer is NULL */
	if (!head)
		return (NULL);

	/* allocate for new node */
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	/* initialize new node */
	new->n = n;
	new->next = NULL;

	/* copy head pointer to interate through list */
	temp = *head;

	/* if list is empty, new node is first/last */
	if (!temp)
	{
		*head = new;
		return (new);
	}
	/* locate end of list */
	while (temp->next)
	{
		temp = temp->next;
	}

	/* point old end to new end */
	temp->next = new;

	return (new);
}
