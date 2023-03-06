#include "lists.h"
int _strlen(const char *s);
/**
 * add_node_end - append node to end of list
 * @head: pointer to list head
 * @str: value to copy to new node
 *
 * Return: pointer to new end node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *temp;
	list_t node;

	if (!str || !head)
		return (NULL);

	/* copy list head pointer to temp for  iteration */
	temp = *head;

	/* assign pointer to new node */
	new = &node;

	/* allocate for new node */
	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	/**
	 * allocate for string member
	 * new->str = malloc(sizeof(char) * (_strlen(str)));
	 * if (!new->str)
	 * {
	 *	free(new);
	 *	return (NULL);
	 * }
	 */

	/* initialize new node */
	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	new->len = _strlen(new->str);
	new->next = NULL;

	/* if list is null, assign new node as head */
	if (temp)
	{
		/* find end of head list */
		while (temp->next)
			temp = temp->next;
		/* point current end node to new end node */
		temp->next = new;
	}
	else
		*head = new;

	return (new);
}
/**
* _strlen - Function that finds the length of a string
* @s: string that the length of is found
*
* Return: length of the @s
*/
int _strlen(const char *s)
{
	/* variable to loop through string to get length */
	int len = 0;

	/* Loop through string, checking for null byte */
	while (s[len] != '\0')
		len++;

	/* return length variable once null byte is reached */
	return (len);
}
