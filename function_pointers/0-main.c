#include <stdio.h>
#include <ctype.h>
#include "function_pointers.h"

static void print_name_as_is(char *name)
{
	printf("Hello, my name is %s\n", name);
}

static void print_name_uppercase(char *name)
{
	unsigned int i = 0;

	printf("Hello, my uppercase name is ");
	while (name[i])
	{
		int c = (unsigned char)name[i];
		putchar(islower(c) ? (c - 'a' + 'A') : c);
		i++;
	}
	putchar('\n');
}

int main(void)
{
	print_name("Bob", print_name_as_is);
	print_name("Bob Dylan", print_name_uppercase);
	print_name(NULL, print_name_as_is); /* لا يطبع شيئًا */
	print_name("Adwa", NULL);           /* لا يطبع شيئًا */
	return (0);
}
