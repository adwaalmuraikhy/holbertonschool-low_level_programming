#include "main.h"

/**
 * prime_helper - checks recursively if n has a divisor >= d
 * @n: number to test
 * @d: current divisor candidate
 *
 * Return: 1 if prime, 0 otherwise
 */
int prime_helper(int n, int d)
{
	if ((long)d * (long)d > n)
		return (1);
	if (n % d == 0)
		return (0);
	return (prime_helper(n, d + 1));
}

/**
 * is_prime_number - returns 1 if n is a prime number, otherwise 0
 * @n: integer to test
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	if (n == 2 || n == 3)
		return (1);
	if (n % 2 == 0)
		return (0);
	return (prime_helper(n, 3));
}
