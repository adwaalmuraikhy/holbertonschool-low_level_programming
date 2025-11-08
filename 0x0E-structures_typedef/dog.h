#ifndef DOG_H
#define DOG_H

/*
 * File: dog.h
 * Auth: Adwa Almuraikhy
 * Desc: Header that defines a new type struct dog.
 */

#include <stddef.h>

/**
 * struct dog - basic dog structure
 * @name: dog's name (string)
 * @age: dog's age (float)
 * @owner: owner's name (string)
 *
 * Description: Defines a dog with a name, age and owner.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif /* DOG_H */
