#include "lists.h"
/**
 * find_listint_loop - find loop entry in list
 * @head: start of list
 *
 * Return: address of loop entry on Success, NULL on Fail
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	for (; head; head = head->next)
	{
		for (slow = head->next, fast = head->next->next; slow && fast;)
		{
			if (slow == head || fast == head)
				return (head);

			if (slow == fast)
				break;

			if (!slow->next || !fast->next->next)
				return (NULL);

			slow = slow->next;
			fast = fast->next->next;
		}
	}
	return (NULL);
}
