#include "lists.h"
/**
 * pop_listint - deletes head node
 * @head: pointer to head of list
 *
 * Return: value of deleted node, 0 if empty list
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n_store;

	/* check for empty list */
	if (!(*head))
		return (0);

	/* copy head pointer in temp for deletion */
	temp = *head;

	/* store n value for return after deletion */
	n_store = (*head)->n;

	/* point head to new head node */
	*head = (*head)->next;

	/* free "deleted" node */
	free(temp);

	/* return the valued stored in deleted node */
	return (n_store);
}
