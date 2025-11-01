#include <stdio.h>

/**\n * main - prints the program name, followed by a new line\n * @argc: number of arguments\n * @argv: array of arguments\n *\n * Return: 0 on success\n */
int main(int argc, char *argv[])
{
    (void)argc;
    printf("%s\n", argv[0]);
    return (0);
}
