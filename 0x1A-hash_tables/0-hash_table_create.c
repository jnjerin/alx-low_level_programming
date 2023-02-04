#include "hash_tables.h"
/**
 * hash_table_create - creates hash table
 * @size: size of array
 *
 * Return: pointer to newly allocated table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table = NULL;

	/* allocate new table struct */
	new_table = malloc(sizeof(hash_table_t));
	if (!new_table) /* if malloc fails */
		return (NULL);
	new_table->size = size;

	/* allocare array of pointers */
	new_table->array = malloc(sizeof(void *) * size);
	if (!new_table->array) /* if array alloc fails */
	{
		free(new_table);
		return (NULL);
	}

	return (new_table);
}
