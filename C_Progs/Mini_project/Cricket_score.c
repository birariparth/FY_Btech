//write a program using file handeling used to display runs, wickets, names of batsmen and bowlers, overs, extras, ecomony of bowler, strike rate of batsman, also display date and time of match. store various information in various files and then bring together to display

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct        //defining a structure
{
    char name[MAX];
    int runs;
    int balls;
} Batsman;

typedef struct         //defining a structure
{
    char name[MAX];
    float overs;
    int runs_given;
    int wickets;
} Bowler;


void writeData(Batsman batsmen[], int batsmenCount, Bowler bowlers[], int bowlersCount, int extras)            //function declared to write into the file
{
    FILE *fbats = fopen("batsmen.txt", "w");
    if (!fbats)
    {
        printf("Error opening batsmen.txt\n");
        exit(1);                                    //indicates faliure
    }
     for (int i = 0; i < batsmenCount; i++)
    {
        fprintf(fbats, "%s,%d,%d\n", batsmen[i].name, batsmen[i].runs, batsmen[i].balls);
    }fclose(fbats);
   
    FILE *fball = fopen("bowlers.txt", "w");
    if(!fball)
    {
        printf("Eror opening bowlers.txt\n");
        exit(1);                                  //  //indicates faliure
    }
    for (int i = 0; i < bowlersCount; i++)
    {
        fprintf(fball, "%s,%d,%d\n", bowlers[i].name, bowlers[i].runs_given, bowlers[i].overs, bowlers[i].wickets);
    }fclose(fbats);
   
    FILE *extra = fopen("extras.txt", "w");
    if (!fextra)
    {
        printf("Error opening batsmen.txt\n");
        exit(1);                                    //indicates faliure
    }
    fprintf(fextra, "%d", extras);
    fclose(fextra);
   
    FILE *date = fopen("datetime.txt", "w");
    if (!fdate)
    {
        printf("Error opening batsmen.txt\n");
        exit(1);                                    //indicates faliure
    }
    //date and time commands
   
}

void displayData()            //function delcared for displaying the data
{
    char date[50];
    printf("\nCricket match summary\n\n");
   
    File *date = fopen("datetime.txt", "r")
    if (fdate == NULL)
    {
        printf("Error opening datetime.txt\n");
        exit(1);
    }
    printf("Match Date & Time: %s\n", date);
    fclose(fdate);
   
    printf("Batsmen performance:");
   
    FILE *fbats = fopen("batsmen.txt", "r");)
    if (fdate == NULL)
    {
        printf("Error opening batsmen.txt\n");
        exit(1);
    }
   
    printf("Bowlers performance:");
   
    FILE *fbats = fopen("bowlers.txt", "r");)
    if (fdate == NULL)
    {
        printf("Error opening bowlers.txt\n");
        exit(1);
    }
    while()
   
   
    FILE *fextra = fopen("extras.txt", "r");
    if (fextra == NULL)
    {
        printf("Error opening extras.txt\n");
        return;
    }
    int extras;
    fscanf(fextra, "%d", &extras);
    fclose(fextra);
    printf("\nExtras: %d\n", extras);
}


int main()                                 //main function
{
    int batsmenCount, bowlersCount;
    printf("Enter number of batsmen");
    scanf("%d", &batsmencount);
   
    for (int i = 0; i < batsmenCount; i++)
    {
        printf("\nEnter details for Batsman %d\n", i+1);
        printf("Name: ");
        fgets(batsmen[i].name, MAX, stdin);              
        //batsmen[i].name[strcspn(batsmen[i].name, "\n")] = 0;
   
        printf("Runs scored: ");
        scanf("%d", &batsmen[i].runs);
        printf("Balls faced: ");
        scanf("%d", &batsmen[i].balls);
    }
   
    printf("Enter number of bowlers");
    scanf("%d", &bowlerscount);
   
    for (int i = 0; i < bowlersCount; i++)
    {
        printf("\nEnter details for Bowler %d\n", i+1);
        printf("Name: "); 
        fgets(bowlers[i].name, MAX, stdin);                     
        //bowlers[i].name[strcspn(bowlers[i].name, "\n")] = 0;

        printf("Overs bowled: ");
        scanf("%f", &bowlers[i].overs);
        printf("Runs given: ");
        scanf("%d", &bowlers[i].runs_given);
        printf("Wickets taken: ");
        scanf("%d", &bowlers[i].wickets);
    }  
   
    printf("\nEnter extras: ");
    scanf("%d", &extras);
   
   
    writeData(batsmen, batsmenCount, bowlers, bowlersCount, extras);  //function call
   
    displayData();  //function call
   
    return 0;
}