#include <stdio.h>

struct A
{
    int x;
};

void increment(struct A a, struct A* b)      //pointer is used here
{
    a.x++;
    b->x++;     
}

int main()
{
    struct A a ={10};
    struct A b ={10};

    increment(a, &b);        //address is passed to b
    printf("a.x: %d \t b.x: %d", a.x, b.x);
    return 0;
}