#include "main.h"

/**
 * jack_bauer - prints every minute of the day from 00:00 to 23:59
 *
 * Description: Uses nested loops and _putchar to print all times
 *              in HH:MM format, one per line.
 *
 * Return: void
 */
void jack_bauer(void)
{
	int h;
	int m;

	for (h = 0; h < 24; h++)
	{
		for (m = 0; m < 60; m++)
		{
			_putchar('0' + (h / 10));
			_putchar('0' + (h % 10));
			_putchar(':');
			_putchar('0' + (m / 10));
			_putchar('0' + (m % 10));
			_putchar('\n');
		}
	}
}
