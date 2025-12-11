#include "hash_tables.h"

/**
 * add_new_node - Add a new node at the head of a list.
 * @head: Address of the first node in the list.
 * @key: The key string.
 * @value: The value string.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
hash_node_t *add_new_node(hash_node_t **head,
			  const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

/**
 * update_node_value - Update value of an existing node.
 * @node: Pointer to the node.
 * @value: The new value string.
 *
 * Return: 1 on success, 0 on failure.
 */
int update_node_value(hash_node_t *node, const char *value)
{
	char *new_value;

	new_value = strdup(value);
	if (new_value == NULL)
		return (0);

	free(node->value);
	node->value = new_value;

	return (1);
}

/**
 * hash_table_set - Add or update a key/value pair in a hash table.
 * @ht: Pointer to the hash table.
 * @key: The key string.
 * @value: The value string.
 *
 * Return: 1 on success, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (update_node_value(node, value));
		node = node->next;
	}

	if (add_new_node(&ht->array[index], key, value) == NULL)
		return (0);

	return (1);
}
