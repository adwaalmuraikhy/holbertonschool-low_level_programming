#include "dog.h"

int main(void)
{
    struct dog d1 = {0}, d2 = { "Poppy", 3.5, 0 };

    print_dog(0);          /* يطبع لا شيء */
    print_dog(&d1);        /* Name: (nil), Age: 0.000000, Owner: (nil) */
    print_dog(&d2);        /* Name: Poppy, Age: 3.500000, Owner: (nil) */
    return 0;
}
