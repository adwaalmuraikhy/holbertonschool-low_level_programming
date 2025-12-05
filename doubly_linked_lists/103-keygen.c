#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * f1 - compute index of first char
 * @s: username
 *
 * Return: index in charset
 */
int f1(char *s)
{
	int len;

	len = strlen(s);
	return ((len ^ 59) & 63);
}

/**
 * f2 - compute index of second char
 * @s: username
 *
 * Return: index in charset
 */
int f2(char *s)
{
	int i;
	int sum = 0;

	for (i = 0; s[i]; i++)
		sum += s[i];
	return ((sum ^ 79) & 63);
}

/**
 * f3 - compute index of third char
 * @s: username
 *
 * Return: index in charset
 */
int f3(char *s)
{
	int i;
	unsigned int prod = 1;

	for (i = 0; s[i]; i++)
		prod *= s[i];
	return ((prod ^ 85) & 63);
}

/**
 * f4 - compute index of fourth char
 * @s: username
 *
 * Return: index in charset
 */
int f4(char *s)
{
	int i;
	int max;

	max = s[0];
	for (i = 0; s[i]; i++)
		if (s[i] > max)
			max = s[i];
	srand(max ^ 14);
	return (rand() & 63);
}

/**
 * main - generate key for crackme5
 * @argc: number of arguments
 * @argv: arguments vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	char *username;
	char *c;
	char key[7];
	int len;
	unsigned int sumsq;
	unsigned int r;
	int i;

	if (argc != 2)
		return (1);

	username = argv[1];
	c = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	len = strlen(username);

	key[0] = c[f1(username)];
	key[1] = c[f2(username)];
	key[2] = c[f3(username)];
	key[3] = c[f4(username)];

	sumsq = 0;
	for (i = 0; i < len; i++)
		sumsq += username[i] * username[i];
	key[4] = c[(sumsq ^ 239) & 63];

	r = 0;
	for (i = 0; i < (int)username[0]; i++)
		r = rand();
	key[5] = c[(r ^ 229) & 63];

	key[6] = '\0';

	printf("%s", key);
	return (0);
}
