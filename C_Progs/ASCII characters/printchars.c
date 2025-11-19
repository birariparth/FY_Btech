#include <stdio.h>
#include <windows.h>

// Function to print a character at a specific position
void printAt(int x, int y, char c) {
    printf("\033[%d;%dH%c", y, x, c); // Note: ANSI escape sequences typically use row;column (y;x)
    fflush(stdout); // Ensure the output is immediately displayed
}

int main() {
    // Print 'A' at column 10, row 5
    printAt(10, 5, 'A');

    // Print 'B' at column 20, row 10
    printAt(20, 10, 'B');

    // Move the cursor back to the starting position (optional)
    printf("\033[1;1H");
    fflush(stdout);


    int i, x, y, prevx, prevy;
    x = 10;
    y = 8;

    for (i = 1; i < 20; i++) {
        printAt(x, y, 'O');
        printf("\033[1;1H");
        fflush(stdout);

        prevx = x;
        prevy = y;
        x += 1;
        Sleep(200); // Sleep for 200 msec
        printAt(prevx, prevy, ' ');
    }
    return 0;
}

/*
void main()
{
    int i;

    for (i = 0; i < 256; i++) {
        printf("%d  ->  %c\n", i, i);
    }    
}
*/
