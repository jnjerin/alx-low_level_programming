#include "lists.h"
/**
 * delete_nodeint_at_index - delete node at index
 * @head: pointer to list head
 * @index: index of node to delete
 *
 * Return: 1 on Success, -1 on Fail
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *target; /* tracks node to delete */
	listint_t *prev; /* tracks node preceding node to delete */
	unsigned int i = 1; /* iterator offset by 1 */

	if (!head)
		return (-1);
	target = prev = *head;
	/* if index is zero, point head to second node and return success */
	if (index == 0)
	{
		if (*head)
		{
			*head = (*head)->next;
			free(target);
			return (1);
		}
		else
			return (-1);
	}
	else
	{
		/* loop til index preceding target or til list ends */
		while (i < index && target)
		{
			target = target->next;
			prev = prev->next;
			i++;
		}
		if (i == index) /* if loop ended in success, proceed; else return */
		{
			/* manually shift target pointer onto target node */
			target = target->next;
			/* point node preceding target to node following */
			prev->next = target->next;
			free(target);
		}
		else
			return (-1);
	}
	return (1);
}
