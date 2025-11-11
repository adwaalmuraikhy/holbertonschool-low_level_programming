#include "3-calc.h"

/**
 * main - perform simple operations
 * @argc: arg count
 * @argv: arg vector
 * Return: 0 on success
 *
 * Codes:
 * 98 - wrong arg count
 * 99 - invalid operator
 * 100 - division by zero
 */
int main(int argc, char *argv[])
{
	int a, b;
	int (*f)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	f = get_op_func(argv[2]);
	if (f == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", f(a, b));
	return (0);
}
