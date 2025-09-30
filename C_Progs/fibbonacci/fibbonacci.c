#include <stdio.h>

int main()
{
    int i, n, j, sum, m;

    printf("Enter number of terms needed for fibbonacci sequence");
    scanf("%d", &n);
    i = 0;
    j = 1;
    printf("%d , %d", i, j);
    for(m=2; m<=n; m++)
    {
        sum = i + j;
        printf(" ,%d", sum);
        i = j;
        j = sum;
    }
    return 0;
}
