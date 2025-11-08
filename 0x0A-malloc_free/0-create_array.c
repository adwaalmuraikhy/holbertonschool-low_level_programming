#include <stdlib.h>
#include "main.h"

/**
 * create_array - creates an array of chars and initializes it
 *                with a specific char.
 * @size: size of the array to create
 * @c:    the initialization character
 *
 * Return: pointer to the array, or NULL if size == 0 or malloc fails
 */
char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	if (size == 0)
		return (NULL);

	arr = malloc(size * sizeof(char));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = c;

	return (arr);
}
