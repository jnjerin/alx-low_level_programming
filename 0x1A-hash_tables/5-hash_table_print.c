#include "hash_tables.h"
/**
 * hash_table_print - print hash table
 * @ht: hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *head = NULL;
	unsigned long int i = 0;
	unsigned long int j;

	if (ht) /* if table exists */
	{
		putchar('{');
		while (i < ht->size) /* iterate array */
		{
			if (ht->array[i] != NULL) /* if element is not NULL */
			{
				head = ht->array[i];
				while (head) /* print 'key: value' for list */
				{
					printf("'%s': '%s'", head->key, head->value);
					if (head->next)
						printf(", ");
					head = head->next;
				}
				/* check if other valid entries follow */
				for (j = i + 1; j < ht->size; j++)
					if (ht->array[j]) /* if another key exists in array */
					{
						printf(", "); /* print delimiter */
						break;
					}
			}
			i++;
		}
		printf("}\n");
	}
}
