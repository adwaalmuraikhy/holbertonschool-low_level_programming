#include "main.h"

/**
 * swap_int - swaps the values of two integers.
 * @a: pointer to first integer
 * @b: pointer to second integer
 *
 * Description: Uses a temporary variable to swap *a and *b.
 * If the two pointers are the same (a == b), function does nothing.
 */
void swap_int(int *a, int *b)
{
	int tmp;

	if (a == b)
		return;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
