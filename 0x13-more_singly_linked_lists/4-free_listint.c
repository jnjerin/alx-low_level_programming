#include "lists.h"
/**
 * free_listint - frees list
 * @head: pointer to list to free
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	/* loop to end of list */
	while (head)
	{
		/* copy head pointer to expendable variable */
		temp = head;

		/* free node */
		free(temp);

		/* increment to next node */
		head = head->next;
	}
}
