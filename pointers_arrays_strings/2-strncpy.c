#include "main.h"

/**
 * _strncpy - copies a string, up to n bytes.
 * @dest: destination buffer
 * @src:  source string
 * @n:    maximum number of bytes to copy
 *
 * Description:
 * Behaves like standard strncpy:
 * - Copies at most @n bytes from @src to @dest.
 * - If @src has fewer than @n bytes, pads the rest of @dest with '\0'.
 * - If @src length >= @n, result is NOT forcibly null-terminated.
 *
 * Return: pointer to @dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	/* copy up to n or until null in src */
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	/* pad with '\0' if src ended before n */
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
