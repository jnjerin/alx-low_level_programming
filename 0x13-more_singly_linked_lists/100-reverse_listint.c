#include "lists.h"
/**
 * reverse_listint - reverse a list
 * @head: list to reverse
 *
 * Return: pointer to head of reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *current;
	listint_t *tail;

	/* if list doesn't exist, return NULL */
	if (!head || !(*head))
		return (NULL);

	/* if single element list, return head */
	if (!(*head)->next)
		return (*head);

	/* inititalized pointers to starting positions */
	tail = current = *head;
	*head = (*head)->next;
	tail->next = NULL;

	/* iterate to end of list, repointing nexts */
	while ((*head)->next)
	{
		current = *head;
		*head = (*head)->next;
		current->next = tail;
		tail = current;
	}

	/* reverse end node pointer */
	(*head)->next = tail;

	return (*head);
}
