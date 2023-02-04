#include "hash_tables.h"
/**
 * hash_table_delete - deletes a hash table
 * @ht: hash table to delete
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *head = NULL, *temp = NULL;

	while (i < ht->size) /* iterate array */
	{
		if (ht->array[i]) /* if element has value */
		{
			head = ht->array[i];
			while (head) /* iterate list */
			{
				temp = head;
				head = head->next;
				free(temp->key);
				free(temp->value);
				free(temp);
			}
		}
		i++;
	}
	free(ht->array);
	free(ht);
}
