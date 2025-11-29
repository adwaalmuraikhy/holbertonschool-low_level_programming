#include <stdio.h>

/**
 * first - prints a string before main executes
 *
 * Return: nothing
 */
void __attribute__((constructor)) first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
