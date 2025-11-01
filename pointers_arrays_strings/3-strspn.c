#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: input string
 * @accept: set of accepted bytes
 *
 * Return: number of initial bytes in s found in accept only
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, count = 0;
	int ok;

	for (i = 0; s[i] != '\0'; i++)
	{
		ok = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				ok = 1;
				break;
			}
		}
		if (!ok)
			break;
		count++;
	}
	return (count);
}
