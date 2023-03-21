#include "lists.h"
/**
 * sum_listint - add list values
 * @head: list to add
 *
 * Return: sum on Success, 0 if list is empty
 */
int sum_listint(listint_t *head)
{
	listint_t *temp;
	int sum = 0;

	/* if list NULL/empty return 0 */
	if (!head)
		return (0);

	temp = head;

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}

	return (sum);
}
