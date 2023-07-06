// C program to assign a value to a constant pointer

#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;
    const int *p = &a;
    printf("Value of a is %d\n", *p);
    p = &b;
    printf("Value of b is %d\n", *p);



    return 0;
}