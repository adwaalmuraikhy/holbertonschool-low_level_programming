/*
 * File: 1-array_iterator.c
 * Auth: adwaalmuraikhy
 * Desc: Executes a function on each element of an int array.
 */

#include "function_pointers.h"

/**
 * array_iterator - executes a function given as a parameter
 *                  on each element of an array.
 * @array: pointer to int array.
 * @size:  number of elements in @array.
 * @action: function pointer to apply on each element.
 *
 * Return: Nothing.
 *
 * Note:
 * If @array is NULL, @action is NULL, or @size is 0, the function does nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == 0 || action == 0 || size == 0)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
