#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char** board, int row, int col, char c)
{
    for(int i = 0; i < 9; i++)
    {
        if (board[row][i] == c) 
            return false;

        if (board[i][col] == c)
            return false;

        if (board[3 * (row/3) + i/3][3 * (col/3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solve(char** board)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for(char c = '1'; c <= '9'; c++)
                {
                    if(isValid(board, i, j, c))
                    {
                        board[i][j] = c;

                        if (solve(board))
                            return true;

                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize)
{
    solve(board);
}

int main()
{
    // Sample Sudoku ('.' = empty)
    char* raw[] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };

    // Allocate 2D board dynamically (char**)
    char** board = (char**)malloc(9 * sizeof(char*));
    for (int i = 0; i < 9; i++)
    {
        board[i] = (char*)malloc(10 * sizeof(char)); // 9 chars + '\0'
        for (int j = 0; j < 9; j++)
            board[i][j] = raw[i][j];
    }

    int cols = 9;
    solveSudoku(board, 9, &cols);

    // Print solved Sudoku
    printf("\nSolved Sudoku:\n");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < 9; i++)
        free(board[i]);
    free(board);

    return 0;
}
