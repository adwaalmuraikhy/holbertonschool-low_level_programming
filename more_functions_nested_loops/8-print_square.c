#include "main.h"

/**
 * print_square - prints a square using '#' characters
 * @size: size of the square (width and height)
 *
 * Description: Uses only _putchar. If size <= 0, prints just '\n'.
 */
void print_square(int size)
{
	int r, c;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (r = 0; r < size; r++)
	{
		for (c = 0; c < size; c++)
			_putchar('#');
		_putchar('\n');
	}
}
