#include "function_pointers.h"

/**
 * array_iterator - executes a function on each array element
 * @array: pointer to the int array
 * @size: number of elements in the array
 * @action: pointer to a function that takes int and returns void
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
