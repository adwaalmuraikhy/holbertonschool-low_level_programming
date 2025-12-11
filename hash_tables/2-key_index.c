#include "hash_tables.h"

/**
 * key_index - Gives index of a key
 * @key: The key
 * @size: Size of hash table array
 *
 * Return: Index for this key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
