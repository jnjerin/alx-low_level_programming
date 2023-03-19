#include "lists.h"
const listint_t *find_loop_entry(const listint_t *head);
/**
 * print_listint_safe - print a looping list
 * @head: list head
 *
 * Return: number of nodes in list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node_cnt = 0;
	int entered = 0; /* flags loop entry */
	const listint_t *temp, *entry;

	/* exit if list is empty */
	if (!head)
		return (node_cnt);

	temp = head;
	entry = find_loop_entry(head);

	/* loop until back to head */
	do {
		if (temp == entry)
		{
			if (!entered)
				entered++;
			else
			{
				printf("-> [%p] %d\n", (void *)temp, temp->n);
				break;
			}
		}
		printf("[%p] %d\n", (void *)temp, temp->n);
		node_cnt++;
		temp = temp->next;
	} while (temp);

	return (node_cnt);
}
/**
 * find_loop_entry - find loop entry in list
 * @head: start of list
 *
 * Return: address of loop entry on Success, NULL on Fail
 */
const listint_t *find_loop_entry(const listint_t *head)
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
