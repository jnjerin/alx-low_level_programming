#include "lists.h"
/**
 * free_list - free a linked list
 * @head: list head
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		free(head->str);
		temp = head;
		head = head->next;
		free(temp);
	}
}
