#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_number - checks if a string contains only digits
 * @s: string to check
 *
 * Return: 1 if only digits, 0 otherwise
 */
int is_number(const char *s)
{
	int i;

	if (s == NULL || s[0] == 0)
		return (0);

	for (i = 0; s[i] != 0; i++)
	{
		if (!isdigit((unsigned char)s[i]))
			return (0);
	}
	return (1);
}

/**
 * main - adds positive numbers and prints the result
 * @argc: number of command-line arguments
 * @argv: array of argument strings
 *
 * Return: 0 on success, 1 on error (non-digit argument)
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (!is_number(argv[i]))
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);
	return (0);
}
