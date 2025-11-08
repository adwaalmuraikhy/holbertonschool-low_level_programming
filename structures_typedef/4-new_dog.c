#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - returns the length of a string
 * @s: string to measure
 *
 * Return: length of the string, or 0 if @s is NULL
 */
static int _strlen(const char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * _strcpy - copies a C-string from @src to @dest
 * @dest: destination buffer
 * @src: source string
 *
 * Return: pointer to @dest
 */
static char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (dest == NULL || src == NULL)
		return (dest);

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * new_dog - creates a new dog (deep copy for name & owner)
 * @name: dog's name (must not be NULL)
 * @age: dog's age
 * @owner: owner's name (must not be NULL)
 *
 * Return: pointer to a newly allocated dog_t on success,
 *         or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	int nlen, olen;

	if (name == NULL || owner == NULL)
		return (NULL);

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	nlen = _strlen(name);
	olen = _strlen(owner);

	d->name = malloc((nlen + 1) * sizeof(char));
	if (d == NULL || d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	d->owner = malloc((olen + 1) * sizeof(char));
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	_strcpy(d->name, name);
	_strcpy(d->owner, owner);
	d->age = age;

	return (d);
}
