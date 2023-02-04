#include "hash_tables.h"
/**
 * key_index - find index of key
 * @key: key of item to locate
 * @size: size of hash array
 *
 * Return: index of key; -1 if key not found
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
