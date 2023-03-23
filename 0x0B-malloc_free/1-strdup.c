#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _strdup - duplicate string
 * @str: string to duplicate
 *
 * Return: pointer to duplicate string
 */
char *_strdup(char *str)
{
	char *str_cpy;
	unsigned int i;
	unsigned int len;

	/* check for error case */
	if (str == NULL)
		return (NULL);

	/* obtain str length */
	len = 0;
	while (str[len] != '\0')
		len++;

	/* increment for null-byte */
	len++;

	/* allocate memory for str_cpy */
	str_cpy = malloc(sizeof(*str) * len);

	/* check for malloc fail */
	if (str_cpy == NULL)
		return (NULL);

	/* copy string */
	i = 0;
	while (str[i] != '\0')
	{
		str_cpy[i] = str[i];
		i++;
	}
	return (str_cpy);
}
