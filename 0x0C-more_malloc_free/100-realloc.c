#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _realloc - reallocate memory
 * @ptr: old allocation
 * @old_size: size of old alloc
 * @new_size: size of new alloc
 *
 * Return: newly alloc pointer on Succes, old pointer
 * if old and new size are equal, NULL on Fail
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *re_ptr;
	unsigned int i = 0;

	/* check special cases */
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/* allocate for new pointer */
	re_ptr = malloc(new_size);

	/* check for alloc fail */
	if (re_ptr == NULL)
		return (NULL);

	/* copy old to new */
	if (ptr != NULL)
		for (i = 0; i < old_size && i < new_size; i++)
			*((char *)re_ptr + i) = *((char *)ptr + i);

	/* free old pointer */
	free(ptr);

	/* return new pointer */
	return (re_ptr);
}
