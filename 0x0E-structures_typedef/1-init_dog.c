#include "dog.h"

/**
 * init_dog - initializes a struct dog
 * @d: pointer to the struct to init
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
    if (d == 0)
        return;

    d->name = name;
    d->age = age;
    d->owner = owner;
}
