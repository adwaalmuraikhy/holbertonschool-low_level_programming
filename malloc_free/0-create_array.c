/**
 * File: 0-create_array.c
 * Desc: Implementation of create_array.
 */

#include <stdlib.h>
#include "main.h"

/**
 * create_array - Creates an array of chars and initializes it with a char.
 * @size: The size of the array to allocate.
 * @c: The char to fill the array with.
 *
 * Return: A pointer to the newly allocated array.
 *         NULL if size is 0 or if malloc fails.
 */
char *create_array(unsigned int size, char c)
{
        char *arr;
        unsigned int i;

        if (size == 0)
                return (NULL);

        arr = malloc(size * sizeof(char));
        if (arr == NULL)
                return (NULL);

        for (i = 0; i < size; i++)
                arr[i] = c;

        return (arr);
}

