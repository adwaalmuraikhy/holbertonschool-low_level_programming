#ifndef DOG_H
#define DOG_H

/**
 * struct dog - basic dog structure
 * @name: pointer to the dog's name
 * @age: dog's age
 * @owner: pointer to the owner's name
 */
struct dog
{
    char *name;
    float age;
    char *owner;
};

/* typedef */
typedef struct dog dog_t;

/* prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif /* DOG_H */
