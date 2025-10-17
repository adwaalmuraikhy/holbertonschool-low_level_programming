#include <stdio.h>

/**
 * main - prints all numbers of base 16 in lowercase
 * Return: Always 0
 */
int main(void)
{
	int i;

	for (i = 48; i < 58; i++)  /* 0..9 */
		putchar(i);

	for (i = 97; i < 103; i++) /* a..f */
		putchar(i);

	putchar('\n');
	return (0);
}
