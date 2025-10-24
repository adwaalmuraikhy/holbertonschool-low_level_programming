#include <stdio.h>

/**
 * main - Entry point
 * Description: Prints numbers 1..100 with FizzBuzz rules.
 * For multiples of 3 print "Fizz", for multiples of 5 print "Buzz",
 * and for multiples of both print "FizzBuzz". Values are space-separated.
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			printf("FizzBuzz");
		else if (i % 3 == 0)
			printf("Fizz");
		else if (i % 5 == 0)
			printf("Buzz");
		else
			printf("%d", i);

		if (i < 100)
			printf(" ");
	}

	printf("\n");
	return (0);
}
