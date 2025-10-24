#include "main.h"

/**
 * more_numbers - prints 10 times the numbers from 0 to 14,
 *                followed by a new line.
 *
 * Return: void
 */
void more_numbers(void)
{
	int row, n;

	for (row = 0; row < 10; row++)
	{
		for (n = 0; n <= 14; n++)
		{
			if (n >= 10)
				_putchar('1');           /* 1st occurrence */
			_putchar('0' + (n % 10));    /* 2nd occurrence */
		}
		_putchar('\n');                   /* 3rd occurrence */
	}
}
