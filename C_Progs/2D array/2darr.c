#include <stdio.h>

int main()
{
    int arr[100][100], i, j, r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    printf("\n Enter an array for 2d elements");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
             printf("Enter element at matrix[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
            printf("\t");
        }
    }
    printf("\n The given array is as follows ");
     printf("\nThe entered matrix is:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n"); // Newline after each row
    }

    return 0;
}