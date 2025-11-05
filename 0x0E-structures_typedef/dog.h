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

#endif /* DOG_H */
