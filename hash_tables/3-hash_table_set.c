#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates a key/value pair in the hash table.
 * @ht: Pointer to the hash table.
 * @key: The key (must not be empty).
 * @value: The value associated with the key (will be duplicated).
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *current;
	unsigned long int index;
	char *value_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	/* Update value if key already exists */
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			value_copy = strdup(value);
			if (value_copy == NULL)
				return (0);
			current->value = value_copy;
			return (1);
		}
		current = current->next;
	}

	/* Create new node */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	value_copy = strdup(value);
	if (value_copy == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	new_node->value = value_copy;
	new_node->next = ht->array[index]; /* collision: add at beginning */
	ht->array[index] = new_node;

	return (1);
}
