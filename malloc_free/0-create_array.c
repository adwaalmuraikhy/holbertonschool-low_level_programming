/*
 * File: 0-create_array.c
 * Auth: Adwa Almuraikhy
 * Desc: Implements create_array for the malloc_free project.
 */

#include <stdlib.h>
#include "main.h"

/**
 * create_array - Creates an array of chars and initializes it with a char.
 * @size: The number of bytes to allocate for the array.
 * @c: The character used to fill the allocated array.
 *
 * Return: A pointer to the newly allocated array on success.
 *         NULL if size is 0 or if memory allocation fails.
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

