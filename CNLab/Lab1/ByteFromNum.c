#include <stdio.h>

int main()
{
    int n=258;
    char a,b,c,d;
    a= n & 0xff;
    n=n>>8;
    b= n & 0xff;
    n=n>>16;
    c= n& 0xff;
    n=n>>24;
    d=n&0xff;
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    printf("c=%d\n",c);
    printf("d=%d\n",d);
    return 0;
}