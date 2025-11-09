/*
 * File: 0-malloc_checked.c
 * Auth: Adwa Almuraikhy
 * Desc: malloc_checked - allocate memory or exit(98) on failure.
 */

#include <stdlib.h>

/**
 * malloc_checked - Allocates memory using malloc.
 * @b: Number of bytes to allocate.
 *
 * Return: Pointer to allocated memory.
 *         The process terminates with status 98 if malloc fails.
 */
void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (p == NULL)
		exit(98);

	return (p);
}
