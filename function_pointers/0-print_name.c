/*
 * File: 0-print_name.c
 * Auth: adwaalmuraikhy
 * Desc: Implements print_name - calls a function pointer to print a name.
 */

#include "function_pointers.h"

/**
 * print_name - Calls a function to print a name.
 * @name: Pointer to the name string.
 * @f:    Function pointer that takes (char *) and returns void.
 *
 * Return: Nothing.
 *
 * Note: If either @name or @f is NULL, the function does nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == 0 || f == 0)
		return;

	f(name);
}
