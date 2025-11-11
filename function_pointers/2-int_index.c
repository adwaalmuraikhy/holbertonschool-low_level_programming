#include "function_pointers.h"

/**
 * int_index - searches for an integer using a comparator
 * @array: pointer to the int array
 * @size: number of elements in the array
 * @cmp: pointer to a function that takes int and returns nonzero if match
 *
 * Return: index of first match; -1 if none or on error
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}

	return (-1);
}
