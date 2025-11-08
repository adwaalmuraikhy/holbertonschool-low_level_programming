#include "dog.h"

/**
 * init_dog - initialize a variable of type struct dog
 * @d: pointer to the struct dog to initialize
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Description: Assigns the provided values to the fields of @d
 * if @d isn't NULL.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == (void *)0)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
