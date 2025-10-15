#include <stdio.h>

/**
 * main - prints the lowercase alphabet in reverse
 * Return: Always 0
 */
int main(void)
{
	int c;

	for (c = 122; c >= 97; c--) /* 122='z', 97='a' */
		putchar(c);

	putchar(10); /* '\n' */
	return (0);
}
