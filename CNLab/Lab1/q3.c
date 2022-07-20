#include <stdio.h>
typedef unsigned char BYTE;
int main()
{
    unsigned int value = 258;
    printf("Number: %d\n", value); 
    BYTE a, b, c, d; 

    a = (value & 0xFF);         
    b = ((value >> 8) & 0xFF);  
    c = ((value >> 16) & 0xFF); 
    d = ((value >> 24) & 0xFF); 

    printf("a= %d\n", a);
    printf("b= %d\n", b);
    printf("c= %d\n", c);
    printf("d= %d\n", d);

    return 0;
}