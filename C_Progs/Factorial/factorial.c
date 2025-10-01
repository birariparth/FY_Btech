#include <stdio.h>

void main()
{
    int n, i;
    printf("Enter number of which factorial is to be found ");
    scanf("%d", &n);
    int fact = 1;
    for(i=1; i<=n ;i++)
    {
        fact *= i;

        printf("%d \n", fact);
    }
    printf("Factorial of number is: %d \n", fact);
}