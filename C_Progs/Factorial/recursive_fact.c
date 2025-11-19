#include <stdio.h>

int fact(int n) 
{
  
    // Base Condition 
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

int main() 
{
    printf("Factorial of 5 : %d\n", fact(7));
    return 0;
}