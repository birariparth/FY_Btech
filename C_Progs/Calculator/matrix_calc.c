#include <stdio.h>
#include <stdlib.h>

void performOperation(int arrA[100][100], int arrB[100][100], int arrC[100][100], int r, int c, char o);

void printMatrix(int arr[100][100], int r, int c);

int main()
{
    int arrA[100][100], arrB[100][100], arrC[100][100];
    int r, c;
    char o;

    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    // Input elements for Matrix A
    printf("\nEnter elements for matrix A\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter element at matrixA[%d][%d]: ", i, j);
            scanf("%d", &arrA[i][j]);
        }
    }

    printf("\nThe entered matrix A is:\n");
    printMatrix(arrA, r, c);

    // Input elements for Matrix B
    printf("\nEnter elements for matrix B\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter element at matrixB[%d][%d]: ", i, j);
            scanf("%d", &arrB[i][j]);
        }
    }

    printf("\nThe entered matrix B is:\n");
    printMatrix(arrB, r, c);

    // Menu for operations
    while (1)
    {
        printf("\nEnter operation to perform (+, -, *, /, %, or 0 to exit): ");
        scanf(" %c", &o);

        performOperation(arrA, arrB, arrC, r, c, o);

        if (o == '0')  // Exit if the user enters '0'
        {
            printf("Exiting...\n");
            break;
        }
    }

    return 0;
}

// Function to perform matrix operations
void performOperation(int arrA[100][100], int arrB[100][100], int arrC[100][100], int r, int c, char o)
{
    int i, j, k;

    switch (o)
    {
        case '+':
            for (i = 0; i < r; i++)
            {
                for (j = 0; j < c; j++)
                {
                    arrC[i][j] = arrA[i][j] + arrB[i][j];
                }
            }
            printf("\nResult of Matrix A + Matrix B is:\n");
            printMatrix(arrC, r, c);
            break;

        case '-':
            for (i = 0; i < r; i++)
            {
                for (j = 0; j < c; j++)
                {
                    arrC[i][j] = arrA[i][j] - arrB[i][j];
                }
            }
            printf("\nResult of Matrix A - Matrix B is:\n");
            printMatrix(arrC, r, c);
            break;

        case '*':
            if (c == r)  // Ensure matrices are of compatible sizes for multiplication
            {
                for (i = 0; i < r; i++)
                {
                    for (j = 0; j < c; j++)
                    {
                        arrC[i][j] = 0;  // Initialize the result matrix to zero
                        for (k = 0; k < c; k++)
                        {
                            arrC[i][j] += arrA[i][k] * arrB[k][j];
                        }
                    }
                }
                printf("\nResult of Matrix A * Matrix B is:\n");
                printMatrix(arrC, r, c);
            }
            else
            {
                printf("Matrices are not compatible for multiplication.\n");
            }
            break;

        case '/':
            for (i = 0; i < r; i++)
            {
                for (j = 0; j < c; j++)
                {
                    if (arrB[i][j] != 0)  // Prevent division by zero
                        arrC[i][j] = arrA[i][j] / arrB[i][j];
                    else
                        arrC[i][j] = 0;  // Handle division by zero
                }
            }
            printf("\nResult of Matrix A / Matrix B is:\n");
            printMatrix(arrC, r, c);
            break;

        case '%':
            for (i = 0; i < r; i++)
            {
                for (j = 0; j < c; j++)
                {
                    if (arrB[i][j] != 0)  // Prevent division by zero
                        arrC[i][j] = arrA[i][j] % arrB[i][j];
                    else
                        arrC[i][j] = 0;  // Handle modulus by zero
                }
            }
            printf("\nResult of Matrix A %% Matrix B is:\n");
            printMatrix(arrC, r, c);
            break;

        case '0':
            break;  // Exit case, do nothing here15

        default:
            printf("Invalid input, please try again.\n");
            break;
    }
}

// Function to print a matrix
void printMatrix(int arr[100][100], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}