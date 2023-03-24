#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - concatenate two strings
 * @s1: first string
 * @s2: second string
 * @n: number of chars to concat from s2
 *
 * Return: concatenated string on Success, NULL on Fail
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *cat;
	unsigned int len = 0, cnt, cat_cnt = 0;

	/* get s1 & s2 length */
	if (s1)
		for (cnt = 0; s1[cnt]; cnt++)
			len++;
	if (s2)
		for (cnt = 0; cnt < n && s2[cnt]; cnt++)
			len++;

	/* account for null-byte */
	len++;

	/* allocate mem */
	cat = malloc(sizeof(char) * len);
	if (cat == NULL)
		return (NULL);

	/* conct s1 & s2 */
	if (s1)
		for (cnt = 0; s1[cnt]; cnt++, cat_cnt++)
			cat[cat_cnt] = s1[cnt];

	if (s2)
		for (cnt = 0; cat_cnt < len - 1; cnt++, cat_cnt++)
			cat[cat_cnt] = s2[cnt];

	/* write null-byte */
	cat[cat_cnt] = '\0';

	return (cat);
}
