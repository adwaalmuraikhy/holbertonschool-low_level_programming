#include "main.h"

/**
 * *_strcpy - copy string from src to dest (including '\0')
 * @dest: destination buffer
 * @src: source string
 *
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	/* i is the position in the string */
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
