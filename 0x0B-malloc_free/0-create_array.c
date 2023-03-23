#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * create_array - create and initialize char array
 * @size: array size
 * @c: char to initialize array
 *
 * Return: pointer to array on Success, NULL if size = 0
 */
char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	/* check for error case 0 */
	if (size == 0)
		return (NULL);

	/* allocate memory */
	arr = malloc(sizeof(c) * size);

	if (arr == NULL)
		return (NULL);

	/* copy c to every element of arr */
	for (i = 0; i < size; i++)
		arr[i] = c;

	return (arr);
}
