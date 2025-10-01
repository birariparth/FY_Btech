#include <stdio.h>

int main()
{
    int arr[10], i, temp, j;
    printf("Enter an array for 10 elements to be sorted in order greatest to smallest");
    for(i=0; i<=10; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The given array is as follows");
    for(i=0; i<=10; i++)
    {
        printf("%d ,", arr[i]);
    }
    for(j=0; j<10; j++)
    {
        for(i=0; i<10; i++)
        {
            if(arr[i]>arr[i+1])
            {
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
    }
    printf("\n The sorted array is as follows \n");
    for(i=0; i<=10; i++)
    {
        printf("%d ,", arr[i]);
    }
}