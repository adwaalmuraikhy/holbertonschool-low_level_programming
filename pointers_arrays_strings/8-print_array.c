#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: pointer to memory area
 * @b: constant byte
 * @n: number of bytes to fill
 *
 * Return: pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
        unsigned int i;

        for (i = 0; i < n; i++)
                s[i] = b;

        return (s);
}
#include "main.h"
/**
 * reset_to_98 - updates the value of an int to 98
 * @n: pointer to an int
 */
void reset_to_98(int *n)
{
        *n = 98;
}
#include "main.h"

/**
 * _strcat - concatenates two strings.
 * @dest: destination string buffer (must have enough space)
 * @src:  source string to append
 *
 * Description: Appends @src to @dest, overwriting the terminating
 * null byte of @dest, then adds a new terminating null byte.
 *
 * Return: pointer to the resulting string @dest.
 */
char *_strcat(char *dest, char *src)
{
        int i = 0, j = 0;

        /* move i to the end of dest */
        while (dest[i] != '\0')
                i++;

        /* copy src after dest */
        while (src[j] != '\0')
        {
                dest[i + j] = src[j];
                j++;
        }

        /* add new null terminator */
        dest[i + j] = '\0';

        return (dest);
}
#include "main.h"
#include <stdio.h>

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
void simple_print_buffer(char *buffer, unsigned int size)
{
        unsigned int i;

        i = 0;
        while (i < size)
        {
                if (i % 10)
                        printf(" ");
                if (!(i % 10) && i)
                        printf("\n");
                printf("0x%02x", buffer[i]);
                i++;
        }
        printf("\n");
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
        char buffer[98] = {0};
        char buffer2[98] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

        simple_print_buffer(buffer, 98);
        _memcpy(buffer + 50, buffer2, 10);
        printf("-------------------------------------------------\n");
        simple_print_buffer(buffer, 98);
        return (0);
}
#include "main.h"

/**
 * _memcpy - copies n bytes from memory area src to dest
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
        unsigned int i;

        for (i = 0; i < n; i++)
                dest[i] = src[i];

        return (dest);
}
#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src.
 * @dest: destination string buffer (must have enough space)
 * @src:  source string to append
 * @n:    maximum number of bytes to append from @src
 *
 * Description: Similar to strcat but copies at most @n bytes from @src.
 * Always null-terminates the result.
 *
 * Return: pointer to the resulting string @dest.
 */
char *_strncat(char *dest, char *src, int n)
{
        int i = 0, j = 0;

        /* move i to the end of dest */
        while (dest[i] != '\0')
                i++;

        /* copy up to n bytes from src */
        while (j < n && src[j] != '\0')
        {
                dest[i + j] = src[j];
                j++;
        }

        /* add new null terminator */
        dest[i + j] = '\0';

        return (dest);
}
#include "main.h"

/**
 * swap_int - swaps the values of two integers.
 * @a: pointer to first integer
 * @b: pointer to second integer
 *
 * Description: Uses a temporary variable to swap *a and *b.
 * If the two pointers are the same (a == b), function does nothing.
 */
void swap_int(int *a, int *b)
{
        int tmp;

        if (a == b)
                return;

        tmp = *a;
        *a = *b;
        *b = tmp;
}
#include "main.h"
#include <stdio.h>

int main(void)
{
        char *s = "hello";
        char *f;

        f = _strchr(s, 'l');
        if (f != NULL)
                printf("%s\n", f);
        return (0);
}
#include "main.h"
#include <stddef.h>

/**
 * _strchr - locates a character in a string
 * @s: pointer to the string
 * @c: character to find
 *
 * Return: pointer to first occurrence of c in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
        while (*s)
        {
                if (*s == c)
                        return (s);
                s++;
        }
        if (c == '\0')
                return (s);
        return (NULL);
}
#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: pointer to the string
 *
 * Return: number of characters before the terminating null byte.
 */
int _strlen(char *s)
{
        int len = 0;

        while (s && s[len] != '\0')
                len++;

        return (len);
}
#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
        int i = 0;

        while (i < n && src[i] != '\0')
        {
                dest[i] = src[i];
                i++;
        }

        while (i < n)
        {
                dest[i] = '\0';
                i++;
        }

        return (dest);
}
#include "main.h"

int main(void)
{
    char *str = "I do not fear computers. I fear the lack of them - Isaac Asimov";
    _puts(str);
    return (0);
}
#include "main.h"

/**
 * _puts - Prints a string followed by a new line to stdout
 * @str: Pointer to the string to print
 *
 * Return: Nothing (void)
 */
void _puts(char *str)
{
        int i = 0;

        while (str[i] != '\0')
        {
                _putchar(str[i]);
                i++;
        }
        _putchar('\n');
}
#include "main.h"

/**
 * _strcmp - compares two strings like standard strcmp
 * @s1: first string
 * @s2: second string
 *
 * Return: <0 if s1<s2, 0 if equal, >0 if s1>s2
 */
int _strcmp(char *s1, char *s2)
{
        int i = 0;

        while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
                i++;

        return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: input string
 * @accept: set of accepted bytes
 *
 * Return: number of initial bytes in s found in accept only
 */
unsigned int _strspn(char *s, char *accept)
{
        unsigned int i, j, count = 0;
        int ok;

        for (i = 0; s[i] != '\0'; i++)
        {
                ok = 0;
                for (j = 0; accept[j] != '\0'; j++)
                {
                        if (s[i] == accept[j])
                        {
                                ok = 1;
                                break;
                        }
                }
                if (!ok)
                        break;
                count++;
        }
        return (count);
}
#include "main.h"

/**
 * print_rev - prints a string in reverse followed by a new line
 * @s: pointer to the string
 *
 * Return: void
 */
void print_rev(char *s)
{
        int len = 0;

        if (!s)
        {
                _putchar('\n');
                return;
        }

        while (s[len] != '\0')
                len++;

        while (len > 0)
        {
                _putchar(s[len - 1]);
                len--;
        }
        _putchar('\n');
}
#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 * @a: array of integers
 * @n: number of elements in the array
 */
void reverse_array(int *a, int n)
{
        int i, tmp;

        for (i = 0; i < n / 2; i++)
        {
                tmp = a[i];
                a[i] = a[n - 1 - i];
                a[n - 1 - i] = tmp;
        }
}
#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to scan
 * @accept: set of bytes to match
 *
 * Return: pointer to first byte in s that matches any in accept, or NULL
 */
char *_strpbrk(char *s, char *accept)
{
        int i;

        while (*s)
        {
                for (i = 0; accept[i] != '\0'; i++)
                {
                        if (*s == accept[i])
                                return (s);
                }
                s++;
        }
        return (NULL);
}
#include "main.h"
#include <stdio.h>
int main(void)
{
    char *s = "hello, world";
    char *f = "world";
    char *t = _strstr(s, f);
    printf("%s\n", t);
    return (0);
}
#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: pointer to the string
 *
 * Return: void
 */
void rev_string(char *s)
{
        int i = 0, j = 0;
        char tmp;

        if (!s)
                return;

        /* find length */
        while (s[j] != '\0')
                j++;

        /* reverse in place: swap ends moving inward */
        j--; /* last valid index */
        while (i < j)
        {
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
                i++;
                j--;
        }
}
#include "main.h"

/**
 * string_toupper - changes all lowercase letters of a string to uppercase
 * @s: pointer to the string to modify
 *
 * Return: pointer to the modified string (same address as @s)
 */
char *string_toupper(char *s)
{
        int i = 0;

        if (s == 0)
                return (0);

        while (s[i] != '\0')
        {
                if (s[i] >= 'a' && s[i] <= 'z')
                        s[i] = s[i] - ('a' - 'A');
                i++;
        }
        return (s);
}
#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: the string to search in
 * @needle: the substring to find
 *
 * Return: pointer to start of located substring, or NULL if not found
 */
char *_strstr(char *haystack, char *needle)
{
        char *h, *n;

        if (*needle == '\0')
                return (haystack);

        while (*haystack)
        {
                h = haystack;
                n = needle;
                while (*h && *n && (*h == *n))
                {
                        h++;
                        n++;
                }
                if (*n == '\0')
                        return (haystack);
                haystack++;
        }
        return (NULL);
}
#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @s: Pointer to the string.
 *
 * Word separators: space, tab, newline, ',', ';', '.', '!', '?',
 *                  '"', '(', ')', '{', '}'.
 *
 * Return: Pointer to the modified string.
 */
char *cap_string(char *s)
{
        int i = 0, j;
        char sep[] = " \t\n,;.!?\"(){}";

        if (s[0] >= 'a' && s[0] <= 'z')
                s[0] -= ('a' - 'A');

        for (i = 1; s[i] != '\0'; i++)
        {
                for (j = 0; sep[j] != '\0'; j++)
                {
                        if (s[i - 1] == sep[j] && s[i] >= 'a' && s[i] <= 'z')
                        {
                                s[i] -= ('a' - 'A');
                                break;
                        }
                }
        }
        return (s);
}
#include "main.h"

/**
 * puts2 - prints every other char of a string (starting with index 0),
 *         then a newline
 * @str: pointer to string
 *
 * Return: void
 */
void puts2(char *str)
{
        int i = 0;

        if (!str)
        {
                _putchar('\n');
                return;
        }

        while (str[i] != '\0')
        {
                _putchar(str[i]);
                if (str[i + 1] == '\0')
                        break;
                i += 2;
        }
        _putchar('\n');
}
#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @s: Pointer to the string.
 *
 * Replaces: a/A->4, e/E->3, o/O->0, t/T->7, l/L->1
 * Constraints: only one if and only two loops.
 *
 * Return: Pointer to the modified string.
 */
char *leet(char *s)
{
        int i, j;
        char from[] = "aAeEoOtTlL";
        char to[] =   "4433007711";

        for (i = 0; s[i] != '\0'; i++)
        {
                for (j = 0; from[j] != '\0'; j++)
                {
                        if (s[i] == from[j]) /* only if */
                        {
                                s[i] = to[j];
                                break;
                        }
                }
        }
        return (s);
}
#include "main.h"

/**
 * print_chessboard - prints an 8x8 chessboard
 * @a: 2D array of chars with fixed width 8
 *
 * Return: void
 */
void print_chessboard(char (*a)[8])
{
        int i, j;

        for (i = 0; i < 8; i++)
        {
                for (j = 0; j < 8; j++)
                        _putchar(a[i][j]);
                _putchar('\n');
        }
}
#include "main.h"

/**
 * puts_half - prints the second half of a string, then a newline
 * @str: pointer to string
 *
 * If the length is odd, prints the last n characters where
 * n = (length_of_the_string + 1) / 2
 */
void puts_half(char *str)
{
        int len = 0, start, i;

        if (!str)
        {
                _putchar('\n');
                return;
        }

        while (str[len] != '\0')
                len++;

        if (len % 2 == 0)
                start = len / 2;
        else
                start = (len + 1) / 2;

        for (i = start; i < len; i++)
                _putchar(str[i]);

        _putchar('\n');
}

#include <stdio.h>
#include "main.h"
/**
 * print_array - prints n elements of an integer array
 * @a: pointer to the first element of the array
 * @n: number of elements to print
 */
void print_array(int *a, int n)
{
        int i;
        for (i = 0; i < n; i++)
        {
                if (i > 0)
                        printf(", ");
                printf("%d", a[i]);
        }
        printf("\n");
}

#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sums of the two diagonals
 *                  of a square matrix of integers
 * @a: pointer to the first element of the matrix (as a flat int*)
 * @size: width/height of the square matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
        int i;
        long sum_main = 0;
        long sum_secondary = 0;

        for (i = 0; i < size; i++)
        {
                sum_main += a[i * size + i];
                sum_secondary += a[i * size + (size - 1 - i)];
        }

        printf("%ld, %ld\n", sum_main, sum_secondary);
}
#include <unistd.h>
int _putchar(char c) { return write(1, &c, 1); }


