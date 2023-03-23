#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - concatenates all args
 * @ac: argument count
 * @av: argument(s)
 *
 * Return: pointer to concatenated string, NULL on Fail
 */
char *argstostr(int ac, char **av)
{
	char *sCat;
	int row, col, len = 0, i;

	/* check for NULL cases */
	if (ac == 0 || av == NULL)
		return (NULL);

	/* find total av length */
	for (row = 0; row < ac; row++)
	{
		for (col = 0; av[row][col] != '\0';)
			col++;
		/* account for newline */
		len += ++col;
	}
	/* account for null-byte */
	len++;

	/* allocate mem for sCat */
	sCat = malloc(sizeof(char) * len);

	/* check for malloc fail */
	if (sCat == NULL)
	{
		free(sCat);
		return (NULL);
	}

	/* concatenate in sCat */
	for (row = 0, i = 0; row < ac; row++)
	{
		for (col = 0; av[row][col] != '\0'; col++, i++)
		{
			sCat[i] = av[row][col];
		}
		sCat[i] = '\n';
		i++;
	}
	return (sCat);
}
