#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) 
{
    char stack[1000];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) 
    {
        char ch = s[i];

        if (ch == '(' || ch == '[' || ch == '{') 
        {
            stack[++top] = ch; // push
        } 
        else 
        {
            if (top == -1) return false; // nothing to match
            if ((ch == ')' && stack[top] != '(') ||
                (ch == ']' && stack[top] != '[') ||
                (ch == '}' && stack[top] != '{'))
                return false;
            top--; // pop
        }
    }

    return (top == -1);
}

int main() 
{
    char s[1000];
    printf("Enter brackets: ");
    scanf("%s", s);

    if (isValid(s))
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}

