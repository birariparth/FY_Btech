#include <stdio.h>
void main()
{
    int score = 0;          // Variables
    int ans;
    printf(" Q.1.Which language is OOP?");  // Q.1.
    printf("\n\n1)C \n2)C++ \n3)HTML \n4)Java");
    scanf("%d", &ans);
    
    if (ans == 2)
    {
        score++;
        printf("\nCorrect!");
    }
    else
    {
        score--;
        printf("\nWrong!");
    }
    
    
    
    printf(" \n\nQ.2.What is Git hub used for?");       //Q.2.
    printf("\n\n1)Programming \n2)Version controll \n3)Cloud computing \n4)Portal");
    scanf("%d", &ans);
    
    if (ans == 2)
    {
        score++;
        printf("\nCorrect!");
    }
    else
    {
        score--;
        printf("\nWrong!");
    }
    
    
    
    printf(" \n\nQ.3. What is size of long double?");                    //Q.3.
    printf("\n\n1)1 \n2)4 \n3)8 \n4)16 ");
    scanf("%d", &ans);
    
    if (ans == 4)
    {
        score++;
        printf("\nCorrect!");
    }
    else
    {
        score--;
        printf("\nWrong!");
    }
    
    
    
    printf(" \n\nQ.4.Which header file is used for strings?");               //Q.4.
    printf("\n\n1)string.h \n2)stdlib.h \n3)stdio.h \n4)time.h ");
    scanf("%d", &ans);
    
    if (ans == 1)
    {
        score++;
        printf("\nCorrect!");
    }
    else
    {
        score--;
        printf("\nWrong!");
    }
    
    
    printf(" \n\nQ.5.Which loop executes at least once?");             //Q.5.
    printf("\n\n1) For\n2) While\n3) do while\n4) NOTA");
    scanf("%d", &ans);
    
    if (ans == 3)
    {
        score++;
        printf("\nCorrect!");
    }
    else
    {
        score--;
        printf("\nWrong!");
    }
    
    
    printf("\nYour Score is %d!", score);
}
