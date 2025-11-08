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

/* typedef alias */
typedef struct dog dog_t;

/* prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d); /* (للمهمة 5 لاحقًا) */

#endif /* DOG_H */
