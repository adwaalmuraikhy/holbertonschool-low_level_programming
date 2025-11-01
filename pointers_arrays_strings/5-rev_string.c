#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: pointer to the string
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i = 0, j = 0;
	char tmp;

	if (!s)
		return;

	/* find length */
	while (s[j] != '\0')
		j++;

	/* reverse in place: swap ends moving inward */
	j--; /* last valid index */
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}
