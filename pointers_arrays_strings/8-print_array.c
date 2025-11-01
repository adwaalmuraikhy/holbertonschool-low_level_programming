/*
 * File: 8-print_array.c
 * Auth: Adwa Almuraikhy
 */

#include <stdio.h>
#include "main.h"

/**
 * print_array - prints n elements of an integer array
 * @a: pointer to the first element of the array
 * @n: number of elements to print
 *
 * Return: void
 */
void print_array(int *a, int n)
{
	int i;

	/* blank line after declarations is required by Betty */
	for (i = 0; i < n; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", a[i]);
	}
	printf("\n");
}

