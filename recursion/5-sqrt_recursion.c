#include "main.h"

/**
 * sqrt_helper - recursive helper to find natural sqrt
 * @n: number to compute sqrt of
 * @i: current candidate
 *
 * Return: i if i*i == n, -1 if it passes n, else recurse
 */
int sqrt_helper(int n, int i)
{
	if (i > n / i) /* avoid overflow of i * i */
		return (-1);
	if ((i * i) == n)
		return (i);
	return (sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: input number
 *
 * Return: natural square root, or -1 if none exists
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);
	return (sqrt_helper(n, 2));
}
