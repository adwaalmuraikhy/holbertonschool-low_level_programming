#include <stdio.h>
#include "dog.h"

/**
 * print_dog - prints a struct dog
 * @d: pointer to struct dog
 *
 * Description: If @d is NULL, print nothing.
 * If any string field is NULL, print (nil) for that field.
 */
void print_dog(struct dog *d)
{
	if (d == (void *)0)
		return;

	printf("Name: %s\n", d->name ? d->name : "(nil)");
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}
