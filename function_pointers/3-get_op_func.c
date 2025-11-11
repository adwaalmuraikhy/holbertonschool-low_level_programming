#include "3-calc.h"

/**
 * get_op_func - select function for operator
 * @s: operator string
 * Return: pointer to function, or NULL if no match
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	if (s == NULL || s[1] != '\0')
		return (NULL);

	while (ops[i].op != NULL && *(ops[i].op) != *s)
		i++;

	return (ops[i].f);
}
