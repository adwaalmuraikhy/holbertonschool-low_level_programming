#include "function_pointers.h"

/**
 * print_name - calls a function to print a name
 * @name: pointer to the name string
 * @f: pointer to a function that takes (char *) and returns void
 *
 * Return: Nothing.
 *
 * Description: If either @name or @f is NULL, the function does nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == 0 || f == 0)
		return;

	f(name);
}
