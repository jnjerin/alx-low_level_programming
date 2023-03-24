#include "holberton.h"
#include <stdlib.h>

/**
 * _calloc - allocate and initialize mem
 * @nmemb: number of elements to allocate
 * @size: size of element (bytes)
 *
 * Return: void pointer to mem on Success, NULL on Fail
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int i;

	/* check for fail cases */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* allocate memory */
	ptr = malloc(nmemb * size);

	/* check for alloc fail */
	if (ptr == NULL)
		return (NULL);

	/* initialize memory */
	for (i = 0; i < (nmemb * size); i++)
		*((char *)ptr + i) = 0;

	/* return pointer to alloc memory */
	return (ptr);
}
