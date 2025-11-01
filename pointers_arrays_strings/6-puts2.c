#include "main.h"

/**
 * puts2 - prints every other char of a string (starting with index 0),
 *         then a newline
 * @str: pointer to string
 *
 * Return: void
 */
void puts2(char *str)
{
	int i = 0;

	if (!str)
	{
		_putchar('\n');
		return;
	}

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		if (str[i + 1] == '\0')
			break;
		i += 2;
	}
	_putchar('\n');
}
