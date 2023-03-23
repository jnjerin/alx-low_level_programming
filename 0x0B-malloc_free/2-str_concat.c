#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * str_concat - concatenate two strings
 * @s1: first string of concat
 * @s2: second string of concat
 *
 * Return: concatenated string on Success, NULL on Fail
 */
char *str_concat(char *s1, char *s2)
{
	char *sCat;
	int i, j = 0;
	unsigned int len = 0;

	/* take length of strings, accounting for null-byte */
	for (i = 0; s1 != NULL && s1[i] != '\0'; i++)
		len++;
	for (i = 0; s2 != NULL && s2[i] != '\0'; i++)
		len++;
	len++;

	/* allocate mem for sCat */
	sCat = malloc(sizeof(char) * len);
	if (sCat == NULL)
		return (NULL);

	/* copy s1 and s2 successively to sCat, end with '\0' */
	for (i = 0; s1 != NULL && s1[i] != '\0'; i++, j++)
		sCat[j] = s1[i];
	for (i = 0; s2 != NULL && s2[i] != '\0'; i++, j++)
		sCat[j] = s2[i];
	sCat[j] = '\0';

	return (sCat);
}
