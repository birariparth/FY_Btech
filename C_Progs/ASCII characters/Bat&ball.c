#include <stdio.h>
#include <windows.h>

// Function to print a character at a specific position
void printAt(int x, int y, char c) {
    printf("\033[%d;%dH%c", y, x, c);
    fflush(stdout);
}

// Function to draw a simple cricket bat
void drawBat(int x, int topY) {
    // Handle (thin vertical)
    for (int i = 0; i < 3; i++) {
        printAt(x, topY + i, '|');
    }
    // Blade (wider rectangle)
    for (int i = 3; i < 7; i++) {
        printAt(x - 1, topY + i, '#');
        printAt(x, topY + i, '#');
        printAt(x + 1, topY + i, '#');
    }
}

int main() {
    system("cls"); // Clear screen

    int batX = 40;
    int batTopY = 5;

    // Draw the bat
    drawBat(batX, batTopY);

    // Ball starting position
    int x = 10;
    int y = 8;
    int prevx, prevy;

    // Move ball
    for (int i = 0; i < 30; i++) {
        printAt(x, y, 'O');           // draw ball
        Sleep(200);                    // wait 200ms
        prevx = x;
        prevy = y;
        printAt(prevx, prevy, ' ');   // erase previous ball
        x += 1;                        // move right
    }

    // Move cursor to bottom after animation
    printAt(1, 20, ' ');
    return 0;
}
