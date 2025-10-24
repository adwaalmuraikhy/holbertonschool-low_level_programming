#include "main.h"

/**
 * print_line - draws a straight line in the terminal
 * @n: number of times the character '_' should be printed
 *
 * Description: Uses only _putchar. If n <= 0, prints just '\n'.
 */
void print_line(int n)
{
	int i;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0; i < n; i++)
		_putchar('_');

	_putchar('\n');
}
