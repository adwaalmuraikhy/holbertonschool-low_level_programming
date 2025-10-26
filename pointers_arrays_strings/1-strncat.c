#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src.
 * @dest: destination string buffer (must have enough space)
 * @src:  source string to append
 * @n:    maximum number of bytes to append from @src
 *
 * Description: Similar to strcat but copies at most @n bytes from @src.
 * Always null-terminates the result.
 *
 * Return: pointer to the resulting string @dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	/* move i to the end of dest */
	while (dest[i] != '\0')
		i++;

	/* copy up to n bytes from src */
	while (j < n && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}

	/* add new null terminator */
	dest[i + j] = '\0';

	return (dest);
}
