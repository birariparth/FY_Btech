#include <stdio.h>
struct A
{
    int x;
    char c;
};

struct B
{
    int y;
    struct A a;
};

int main()
{
    struct B p = {7, 195, 'd'};

    printf("p.y =  %d\n", p.y);
    printf("p.a.x = %d\n", p.a.x);
    printf("p.a.c = %c", p.a.c);
    return 0;
}
