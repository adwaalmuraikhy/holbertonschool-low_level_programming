#include <stdlib.h>
#include "dog.h"

/* helpers */
static int _strlen(const char *s)
{
	int i = 0;
	if (!s)
		return 0;
	while (s[i])
		i++;
	return i;
}

static char *_strcpy(char *dest, const char *src)
{
	int i = 0;
	if (!dest || !src)
		return dest;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

/**
 * new_dog - creates a new dog (deep copy for name & owner)
 * @name: dog's name (must not be NULL)
 * @age: dog's age
 * @owner: dog's owner (must not be NULL)
 *
 * Return: pointer to newly allocated dog_t on success, NULL on failure.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	int nlen, olen;

	if (name == NULL || owner == NULL)
		return NULL;

	d = (dog_t *)malloc(sizeof(dog_t));
	if (d == NULL)
		return NULL;

	nlen = _strlen(name);
	olen = _strlen(owner);

	d->name = (char *)malloc((nlen + 1) * sizeof(char));
	if (d->name == NULL)
	{
		free(d);
		return NULL;
	}

	d->owner = (char *)malloc((olen + 1) * sizeof(char));
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return NULL;
	}

	_strcpy(d->name, name);
	_strcpy(d->owner, owner);
	d->age = age;

	return d;
}
