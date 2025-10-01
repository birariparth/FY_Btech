#include <stdio.h>
struct A     //defining a structure
{
    int x;
};

int main()
{
    struct A a;     //creating structure variable
    
    a.x = 11;        //initializing member

    printf("%d", a.x);
    return 0;
}