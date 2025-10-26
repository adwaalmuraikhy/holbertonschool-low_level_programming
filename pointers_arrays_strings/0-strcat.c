#include "main.h"

/**
 * _strcat - concatenates two strings.
 * @dest: destination string buffer (must have enough space)
 * @src:  source string to append
 *
 * Description: Appends @src to @dest, overwriting the terminating
 * null byte of @dest, then adds a new terminating null byte.
 *
 * Return: pointer to the resulting string @dest.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	/* move i to the end of dest */
	while (dest[i] != '\0')
		i++;

	/* copy src after dest */
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}

	/* add new null terminator */
	dest[i + j] = '\0';

	return (dest);
}
