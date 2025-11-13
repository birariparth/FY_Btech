#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX 50

typedef struct
{
    char name[MAX];
    int runs;
    int balls;
} Batsman;

typedef struct
{
    char name[MAX];
    float overs;
    int runs_given;
    int wickets;
} Bowler;

//Function to write all data to text files

void writeData(Batsman batsmen[], int batsmenCount, Bowler bowlers[], int bowlersCount, int extras)
{
    FILE *fbats = fopen("batsmen.txt", "w");
    if (!fbats)
    {
        printf("Error opening batsmen.txt\n");
        exit(1);
    }
    for (int i = 0; i < batsmenCount; i++)
    {
        fprintf(fbats, "%s,%d,%d\n", batsmen[i].name, batsmen[i].runs, batsmen[i].balls);
    }
    fclose(fbats);

    FILE *fball = fopen("bowlers.txt", "w");
    if (!fball)
    {
        printf("Error opening bowlers.txt\n");
        exit(1);
    }
    for (int i = 0; i < bowlersCount; i++)
    {
        fprintf(fball, "%s,%.1f,%d,%d\n", bowlers[i].name, bowlers[i].overs, bowlers[i].runs_given, bowlers[i].wickets);
    }
    fclose(fball);

    FILE *fextra = fopen("extras.txt", "w");
    if (!fextra)
    {
        printf("Error opening extras.txt\n");
        exit(1);
    }
    fprintf(fextra, "%d", extras);
    fclose(fextra);

    FILE *fdate = fopen("datetime.txt", "w");
    if (!fdate)
    {
        printf("Error opening datetime.txt\n");
        exit(1);
    }
    time_t t = time(NULL);         //using epoch format specifer to access time
    struct tm tm = *localtime(&t);      //used to convert t seconds into readable format
    fprintf(fdate, "%04d-%02d-%02d %02d:%02d:%02d\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(fdate);
}

//Function to display saved match summary

void displayData()
{
    char line[100];

    printf("\n--- Cricket Match Summary ---\n\n");



    FILE *fdate = fopen("datetime.txt", "r");
    if (fdate && fgets(line, sizeof(line), fdate))    //using size of so not to overflow reading and fgets reads until newline or maximum length
    {
        printf("Match Date & Time: %s\n", line);
    }
    fclose(fdate);



    printf("Batsmen Performance:\n");
    printf("%-20s %-5s %-5s %-12s\n", "Name", "Runs", "Balls", "Strike Rate");
    FILE *fbats = fopen("batsmen.txt", "r");
    if (!fbats)
    {
        printf("Error opening batsmen.txt\n");
        return;
    }
    while (fgets(line, sizeof(line), fbats))
    {
        char name[MAX]; int runs, balls;
        sscanf(line, "%[^,],%d,%d", name, &runs, &balls);
        float sr = balls > 0 ? ((float)runs / balls) * 100 : 0.0;
        printf("%-20s %-5d %-5d %-12.2f\n", name, runs, balls, sr);
    }
    fclose(fbats);



    printf("\nBowlers Performance:\n");
    printf("%-20s %-7s %-8s %-8s %-8s\n", "Name", "Overs", "Runs", "Wickets", "Economy");
    FILE *fball = fopen("bowlers.txt", "r");
    if (!fball)
    {
        printf("Error opening bowlers.txt\n");
        return;
    }
    while (fgets(line, sizeof(line), fball))
    {
        char name[MAX]; float overs; int runs, wkts;
        sscanf(line, "%[^,],%f,%d,%d", name, &overs, &runs, &wkts);
        float eco = overs > 0 ? runs / overs : 0.0;
        printf("%-20s %-7.1f %-8d %-8d %-8.2f\n", name, overs, runs, wkts, eco);
    }
    fclose(fball);



    FILE *fextra = fopen("extras.txt", "r");
    if (!fextra)
    {
        printf("Error opening extras.txt\n");
        return;
    }
    int extras;
    fscanf(fextra, "%d", &extras);
    fclose(fextra);

    printf("\nExtras: %d\n", extras);
}


//Main program

int main()
{
    int batsmenCount, bowlersCount, extras;

    printf("Enter number of batsmen: ");
    scanf("%d", &batsmenCount);
    getchar(); // consume newline

    Batsman batsmen[batsmenCount];
    for (int i = 0; i < batsmenCount; i++)
    {
        printf("\nEnter details for Batsman %d\n", i + 1);
        printf("Name: ");
        fgets(batsmen[i].name, MAX, stdin);
        batsmen[i].name[strcspn(batsmen[i].name, "\n")] = 0;

        printf("Runs scored: ");
        scanf("%d", &batsmen[i].runs);
        printf("Balls faced: ");
        scanf("%d", &batsmen[i].balls);
        getchar();

        // --- Validation checks ---
        if (batsmen[i].runs < 0 || batsmen[i].balls < 0)
        {
            printf("Error: Negative values not allowed.\n");
            i--; continue;
        }
        if (batsmen[i].balls == 0 && batsmen[i].runs > 0)
        {
            printf("Error: Runs scored with 0 balls is impossible!\n");
            i--; continue;
        }
        if (batsmen[i].runs > batsmen[i].balls * 6)
        {
            printf("Error: %s scored %d runs in %d balls — impossible!\n",
                   batsmen[i].name, batsmen[i].runs, batsmen[i].balls);
            i--; continue;
        }
    }

    printf("\nEnter number of bowlers: ");
    scanf("%d", &bowlersCount);
    getchar();

    Bowler bowlers[bowlersCount];
    float totalOvers = 0.0;
    int totalWickets = 0;

    for (int i = 0; i < bowlersCount; i++)
    {
        printf("\nEnter details for Bowler %d\n", i + 1);
        printf("Name: ");
        fgets(bowlers[i].name, MAX, stdin);
        bowlers[i].name[strcspn(bowlers[i].name, "\n")] = 0;

        printf("Overs bowled: ");
        scanf("%f", &bowlers[i].overs);
        printf("Runs given: ");
        scanf("%d", &bowlers[i].runs_given);
        printf("Wickets taken: ");
        scanf("%d", &bowlers[i].wickets);
        getchar();

        // --- Validation checks ---
        if (bowlers[i].overs < 0 || bowlers[i].runs_given < 0 || bowlers[i].wickets < 0)
        {
            printf("Error: Negative values are invalid.\n");
            i--; continue;
        }

        int whole = (int)bowlers[i].overs;
        int balls = (int)round((bowlers[i].overs - whole) * 10);
        if (balls > 5)
        {
            printf("Error: Invalid overs (%.1f) — fractional part cannot exceed .5 (6 balls).\n", bowlers[i].overs);
            i--; continue;
        }

        totalOvers += bowlers[i].overs;
        totalWickets += bowlers[i].wickets;

        if (totalOvers > 50.0)
        {
            printf("Error: Total overs exceed 50 (%.1f so far).\n", totalOvers);
            totalOvers -= bowlers[i].overs;
            totalWickets -= bowlers[i].wickets;
            i--; continue;
        }
        if (totalWickets > 10)
        {
            printf("Error: Total wickets exceed 10 (%d so far).\n", totalWickets);
            totalOvers -= bowlers[i].overs;
            totalWickets -= bowlers[i].wickets;
            i--; continue;
        }
    }

    printf("\nEnter extras: ");
    scanf("%d", &extras);
    if (extras < 0)
    {
        printf("Error: Extras cannot be negative.\n");
        return 1;
    }

    int totalRuns = extras;
    for (int i = 0; i < batsmenCount; i++)
        totalRuns += batsmen[i].runs;

    //Save and display summary
    writeData(batsmen, batsmenCount, bowlers, bowlersCount, extras);

    printf("\nData recorded successfully!");
    printf("\nTotal Team Score: %d/%d in %.1f overs\n", totalRuns, totalWickets, totalOvers);

    displayData();

    return 0;
}