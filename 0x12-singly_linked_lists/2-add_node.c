#include "lists.h"
int _strlen(const char *s);
/**
 * add_node - link new node at beginning of list
 * @head: current list head
 * @str: value to initialize in new node
 *
 * Return: pointer to new list head
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	list_t node;

	new = &node;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	new->str = malloc(sizeof(char) * (_strlen(str)));
	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	/* initialize new node */
	new->str = strdup(str);
	new->len = _strlen(new->str);
	new->next = *head;

	*head = new;

	return (*head);
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
