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
	return ((len ^ 0x3b) & 0x3f);
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
	return ((sum ^ 0x4f) & 0x3f);
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
	int prod = 1;

	for (i = 0; s[i]; i++)
		prod *= s[i];
	return ((prod ^ 0x55) & 0x3f);
}

/**
 * f4_seed - compute seed for rand
 * @s: username
 *
 * Return: seed value
 */
int f4_seed(char *s)
{
	int i;
	int max;

	max = s[0];
	for (i = 0; s[i]; i++)
	{
		if (s[i] > max)
			max = s[i];
	}
	return (max ^ 0xe);
}

/**
 * main - keygen for crackme5
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	const char *g = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char key[7];
	char *user;
	int i;
	int sum;
	int len;
	int rnd;

	if (argc != 2)
		return (1);

	user = argv[1];

	key[0] = g[f1(user)];
	key[1] = g[f2(user)];
	key[2] = g[f3(user)];

	srand(f4_seed(user));
	key[3] = g[rand() & 0x3f];

	sum = 0;
	for (i = 0; user[i]; i++)
		sum += user[i] * user[i];
	key[4] = g[(sum ^ 0xef) & 0x3f];

	len = user[0];
	rnd = 0;
	for (i = 0; i < len; i++)
		rnd = rand();
	key[5] = g[(rnd ^ 0xe5) & 0x3f];

	key[6] = '\0';
	printf("%s", key);
	return (0);
}
