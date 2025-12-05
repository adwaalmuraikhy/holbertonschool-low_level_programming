#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        char *charset;
        char key[7];
        int len;
        unsigned int hash;
        int i;

        if (argc != 2)
                return (1);

        username = argv[1];
        charset =
"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
        len = strlen(username);

        hash = (len ^ 59) & 63;
        key[0] = charset[hash];

        hash = 0;
        for (i = 0; i < len; i++)
                hash += username[i];
        key[1] = charset[(hash ^ 79) & 63];

        hash = 1;
        for (i = 0; i < len; i++)
                hash *= username[i];
        key[2] = charset[(hash ^ 85) & 63];

        hash = 0;
        for (i = 0; i < len; i++)
                if (username[i] > (int)hash)
                        hash = username[i];
        srand(hash ^ 14);
        key[3] = charset[rand() & 63];

        hash = 0;
        for (i = 0; i < len; i++)
                hash += username[i] * username[i];
        key[4] = charset[(hash ^ 239) & 63];

        hash = 0;
        for (i = 0; i < username[0]; i++)
                hash = rand();
        key[5] = charset[(hash ^ 229) & 63];

        key[6] = '\0';
        printf("%s\n", key);

        return (0);
}
