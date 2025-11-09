/*
 * File: 3-array_range.c
 * Auth: Adwa Almuraikhy
 * Desc: array_range - create an int array from min to max (inclusive).
 */

#include <stdlib.h>

/**
 * array_range - creates an array of ints from @min to @max inclusive
 * @min: starting value
 * @max: ending value
 *
 * Return: pointer to newly allocated array,
 *         or NULL if min > max or malloc fails.
 */
int *array_range(int min, int max)
{
	int *a;
	int len, i, v;

	if (min > max)
		return (NULL);

	len = max - min + 1;

	a = malloc(sizeof(int) * len);
	if (a == NULL)
		return (NULL);

	for (i = 0, v = min; i < len; i++, v++)
		a[i] = v;

	return (a);
}

