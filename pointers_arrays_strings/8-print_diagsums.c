#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sums of the two diagonals
 *		    of a square matrix of integers
 * @a: pointer to the first element of the matrix (as a flat int*)
 * @size: width/height of the square matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i;
	long sum_main = 0;
	long sum_secondary = 0;

	for (i = 0; i < size; i++)
	{
		sum_main += a[i * size + i];
		sum_secondary += a[i * size + (size - 1 - i)];
	}

	printf("%ld, %ld\n", sum_main, sum_secondary);
}
