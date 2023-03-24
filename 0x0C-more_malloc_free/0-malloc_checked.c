#include "holberton.h"
#include <stdlib.h>

/**
 * malloc_checked - allocate memory
 * @b: bytes to allocate
 *
 * Return: void pointer to allocated mem
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
	{
		free(ptr);
		exit(98);
	}

	return (ptr);
}
