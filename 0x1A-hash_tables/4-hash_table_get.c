#include "hash_tables.h"
/**
 * hash_table_get - retrieve value from hash table
 * @ht: pointer to hash table
 * @key: key of value to return
 *
 * Return: value at key; NULL on failure
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t *head = NULL;

	if (!ht || !key)
		return (NULL);

	/* get index of key */
	index = hash_djb2((unsigned char *)key) % ht->size;

	if (ht->array[index]) /* if pointer at index is not NULL */
	{
		head = ht->array[index];
		while (head)
		{
			if (strcmp(head->key, key) == 0)
				break;
			head = head->next;
		}
	}
	else /* key doesn't exist in table */
		return (NULL);

	return (head->value);
}
