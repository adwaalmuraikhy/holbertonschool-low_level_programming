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
