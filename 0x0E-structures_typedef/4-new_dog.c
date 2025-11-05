#include <stdlib.h>
#include "dog.h"

static int _strlen(char *s)
{
    int i = 0;

    if (s == 0)
        return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}

static char *_strcpy(char *dest, char *src)
{
    int i = 0;

    if (src == 0)
    {
        dest[0] = '\0';
        return (dest);
    }
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

/**
 * new_dog - creates a new dog (deep copy)
 * @name: dog's name
 * @age: dog's age
 * @owner: owner's name
 *
 * Return: pointer to new dog (dog_t) or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *p;
    int ln, lo;

    p = (dog_t *)malloc(sizeof(dog_t));
    if (p == 0)
        return (0);

    ln = _strlen(name);
    lo = _strlen(owner);

    p->name = (char *)malloc(ln + 1);
    if (p->name == 0)
    {
        free(p);
        return (0);
    }

    p->owner = (char *)malloc(lo + 1);
    if (p->owner == 0)
    {
        free(p->name);
        free(p);
        return (0);
    }

    _strcpy(p->name, name);
    _strcpy(p->owner, owner);
    p->age = age;

    return (p);
}
