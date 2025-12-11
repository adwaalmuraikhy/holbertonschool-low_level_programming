#include "hash_tables.h"

/**
 * hash_table_print - Prints the key/value pairs in a hash table.
 * @ht: Pointer to the hash table.
 *
 * Description: Prints elements in the order they appear in the array,
 *              handling linked lists (collisions) in array order.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	int first_printed = 0;

	if (ht == NULL)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			if (first_printed == 1)
				printf(", ");

			printf("'%s': '%s'", node->key, node->value);
			first_printed = 1;

			node = node->next;
		}
	}

	printf("}\n");
}
