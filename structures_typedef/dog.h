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

/* New typedef alias for struct dog (task 3) */
typedef struct dog dog_t;

/* Prototypes from previous tasks */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_H */
