#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - generate a valid key for crackme5
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	char *user;
	char key[7];
	char max_char;
	char *charset;
	size_t i, j;
	int rnd;

	if (argc != 2)
		return (1);

	user = argv[1];
	charset = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxq"
		  "ZeF3Qa1rPhdKIouk";

	/* 1st char */
	j = (strlen(user) ^ 0x3b) & 0x3f;
	key[0] = charset[j];

	/* 2nd char */
	j = 0;
	for (i = 0; user[i]; i++)
		j += user[i];
	key[1] = charset[(j ^ 0x4f) & 0x3f];

	/* 3rd char */
	j = 1;
	for (i = 0; user[i]; i++)
		j *= user[i];
	key[2] = charset[(j ^ 0x55) & 0x3f];

	/* 4th char */
	max_char = user[0];
	for (i = 0; user[i]; i++)
		if (user[i] > max_char)
			max_char = user[i];
	srand(max_char ^ 0xe);
	j = rand();
	key[3] = charset[j & 0x3f];

	/* 5th char */
	j = 0;
	for (i = 0; user[i]; i++)
		j += user[i] * user[i];
	key[4] = charset[(j ^ 0xef) & 0x3f];

	/* 6th char */
	max_char = user[0];
	while (max_char--)
		rnd = rand();
	key[5] = charset[(rnd ^ 0xe5) & 0x3f];

	key[6] = '\0';
	printf("%s", key);

	return (0);
}
