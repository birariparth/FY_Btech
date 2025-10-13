//armstrong number
#include <stdio.h>

int main() 
{
    int num, rev, rem, sum, n, temp, temp2;
    rev = 0;
    int arm = 0;
    n = 0;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    temp = num;
    temp2 = num;
    
    while(temp != 0)
    {
        temp = temp / 10;
        n++;
    }
    temp = num;
    while(temp!=0)
    {
        rem = temp % 10;
        sum = 1;
        for(int i = 1; i<=n; i++)
        {
            sum = sum*rem;
        }
        arm = arm+sum;
        temp = temp/10;
    }
    if(arm == temp2)
    {
        printf("Number is Armstrong");
    }
    else
    {
        printf("Number is not armstrong");
    }
    return 0;
}