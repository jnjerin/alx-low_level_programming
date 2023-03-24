#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * array_range - create range of ints
 * @min: first number of range
 * @max: last number of range
 *
 * Return: pointer to int array, NULL on Fail
 */
int *array_range(int min, int max)
{
	int *range;
	int i;

	/* check for fail cases */
	if (min > max)
		return (NULL);

	/* allocate mem */
	range = malloc(sizeof(int) * ((max - min) + 1));

	/* check for alloc fail */
	if (range == NULL)
		return (NULL);

	/* initialize range */
	for (i = 0; min + i <= max; i++)
	{
		*(range + i) = min + i;
	}

	/* return pointer */
	return (range);
}
