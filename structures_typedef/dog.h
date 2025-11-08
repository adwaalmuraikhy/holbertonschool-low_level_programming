#ifndef DOG_H
#define DOG_H

/**
 * struct dog - basic dog structure
 * @name: dog's name (string)
 * @age:  dog's age (float)
 * @owner: owner's name (string)
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/* Prototype for task 1 */
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* DOG_H */
