#include<stdio.h>
int main()
{
    int year;

    printf("Enter the year to check if it is leap year or not ");
    scanf("%d", &year);
    int leap = year % 4;
    
    if (leap == 0)
        printf("Year is leap year");
    else
        printf("Year is not leap year");

    return 0;
}