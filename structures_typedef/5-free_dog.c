#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees memory of a dog_t structure
 * @d: pointer to the dog to free
 *
 * Description: Frees name, owner, then the struct itself.
 * If @d is NULL, does nothing.
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}
