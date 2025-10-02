#include <stdio.h>
typedef struct
{
    int a;
}str1;

int main()
{
    str1 var1 = {20};
    printf("var1.a = %d", var1.a);
    return 0;
}