/*
 * File: 2-calloc.c
 * Auth: Adwa Almuraikhy
 * Desc: _calloc - allocate zero-initialized array memory (like calloc).
 */

#include <stdlib.h>

/**
 * _calloc - allocates memory for an array and sets it to zero
 * @nmemb: number of elements
 * @size:  size in bytes of each element
 *
 * Return: pointer to zero-initialized memory on success,
 *         NULL if nmemb or size is 0, or if malloc fails.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i, total;
	unsigned char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total = nmemb * size;

	p = malloc(total);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		p[i] = 0;

	return ((void *)p);
}

