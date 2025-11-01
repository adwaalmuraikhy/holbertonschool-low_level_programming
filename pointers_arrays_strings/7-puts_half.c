/*
 * File: 7-puts_half.c
 * Auth: Adwa Almuraikhy
 */

#include "main.h"

/**
 * puts_half - prints the second half of a string, then a newline
 * @str: pointer to string
 *
 * If the length is odd, it prints the last n characters where
 * n = (length_of_the_string + 1) / 2.
 *
 * Return: void
 */
void puts_half(char *str)
{
	int len = 0;
	int start;
	int i;

	if (!str)
	{
		_putchar('\n');
		return;
	}

	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
		start = len / 2;
	else
		start = (len + 1) / 2;

	for (i = start; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}

