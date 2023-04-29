#include <stdio.h>
int main()
{
    int x = 258;
    char c= x & 0xFF;

    printf("Value is: %d\n", x);
    if (c == 2)
    {
        printf("Underlying architecture is little endian. \n");
    }
    else
    {
        printf("Underlying architecture is big endian. \n");
    }

    return 0;
}