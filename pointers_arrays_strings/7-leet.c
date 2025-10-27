#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @s: Pointer to the string.
 *
 * Replaces: a/A->4, e/E->3, o/O->0, t/T->7, l/L->1
 * Constraints: only one if, only two loops,
 * no switch and no ternary.
 *
 * Return: Pointer to the modified string.
 */
char *leet(char *s)
{
	int i, j;
	char from[] = "aAeEoOtTlL";
	char to[] =   "4433007711";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; from[j] != '\0'; j++)
		{
			if (s[i] == from[j]) /* only if */
			{
				s[i] = to[j];
				break;
			}
		}
	}
	return (s);
}
