#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>


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

void writeData(Batsman batsmen[], int batsmenCount, Bowler bowlers[], int bowlersCount, int extras, int innings)
{
    char batsFile[150], bowlFile[150], extraFile[150], dateFile[150];   
    //char dir[1024];

    //getcwd(dir, sizeof(dir));
    //printf("\tWriting data of inning %d\n", innings);
    //printf("\t Current directory : %s", dir);

    char basedir[60] = "D:\\Repositories\\FY_Btech\\C_Progs\\cricket_mini_project\\";

    sprintf(batsFile, "%sinnings%d_batsmen.txt", basedir, innings);   
    sprintf(bowlFile, "%sinnings%d_bowlers.txt", basedir, innings);   
    sprintf(extraFile, "%sinnings%d_extras.txt", basedir, innings);   
    sprintf(dateFile, "%sinnings%d_datetime.txt", basedir, innings);  

    FILE *fbats = fopen(batsFile, "w+");    
    if (!fbats)
    {
        printf("Error opening %s\n", batsFile);
        exit(1);
    }
    for (int i = 0; i < batsmenCount; i++)
    {
        fprintf(fbats, "%s,%d,%d\n", batsmen[i].name, batsmen[i].runs, batsmen[i].balls);
    }
    fclose(fbats);

    FILE *fball = fopen(bowlFile, "w+");    
    if (!fball)
    {
        printf("Error opening %s\n", bowlFile);
        exit(1);
    }
    for (int i = 0; i < bowlersCount; i++)
    {
        fprintf(fball, "%s,%.1f,%d,%d\n", bowlers[i].name, bowlers[i].overs, bowlers[i].runs_given, bowlers[i].wickets);
    }
    fclose(fball);

    FILE *fextra = fopen(extraFile, "w+");   
    if (!fextra)
    {
        printf("Error opening %s\n", extraFile);
        exit(1);
    }
    fprintf(fextra, "%d", extras);
    fclose(fextra);

    FILE *fdate = fopen(dateFile, "w+");   
    if (!fdate)
    {
        printf("Error opening %s\n", dateFile);
        exit(1);
    }
    
    time_t t = time(NULL);         //using epoch format specifer to access time
    struct tm tm = *localtime(&t);      //used to convert t seconds into readable format
    fprintf(fdate, "%04d-%02d-%02d %02d:%02d:%02d\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(fdate);

    printf("\tData written to inning %d\n", innings);
}


//Function to display saved match summary

void displayData(int innings)
{
    printf("\n==============================================================\n");
    printf("|               CRICKET MATCH SUMMARY (INNINGS %d)            |\n", innings);
    printf("==============================================================\n");

    char line[150];
    char batsFile[150], bowlFile[150], extraFile[150], dateFile[150];
    
    char basedir[60] = "D:\\Repositories\\FY_Btech\\C_Progs\\cricket_mini_project\\";

    sprintf(batsFile, "%sinnings%d_batsmen.txt", basedir, innings);   
    sprintf(bowlFile, "%sinnings%d_bowlers.txt", basedir, innings);   
    sprintf(extraFile, "%sinnings%d_extras.txt", basedir, innings);   
    sprintf(dateFile, "%sinnings%d_datetime.txt", basedir, innings);  

    FILE *fdate = fopen(dateFile, "r");
    if (fdate && fgets(line, sizeof(line), fdate))
    {
        line[strcspn(line, "\n")] = 0;  // Remove newline
        printf("| Match Date & Time : %-39s|\n", line);
    }


    printf("--------------------------------------------------------------\n");
    printf("|                    Batsmen Performance                     |\n");
    printf("--------------------------------------------------------------\n");
    printf("| %-20s %-10s %-10s %-15s |\n", "Name", "Runs", "Balls", "Strike Rate");

    FILE *fbats = fopen(batsFile, "r");
    if (!fbats) 
    { 
        printf("Error opening batsmen file.\n"); 
        return; 
    }

    while (fgets(line, sizeof(line), fbats))
    {
        char name[MAX]; int runs, balls;
        sscanf(line, "%[^,],%d,%d", name, &runs, &balls);
        float sr = balls > 0 ? (runs * 100.0 / balls) : 0;
        printf("| %-20s %-10d %-10d %-15.2f |\n", name, runs, balls, sr);

    }
    fclose(fbats);

    printf("--------------------------------------------------------------\n");
    printf("|                    Bowlers Performance                     |\n");
    printf("--------------------------------------------------------------\n");
    printf("| %-20s %-8s %-8s %-8s %-10s |\n",
           "Name", "Overs", "Runs", "Wickets", "Economy");

    FILE *fball = fopen(bowlFile, "r");
    if (!fball) 
    { 
        printf("Error opening bowlers file.\n"); 
        return; 
    }

    while (fgets(line, sizeof(line), fball))
    {
        char name[MAX]; float overs; int runs, wkts;
        sscanf(line, "%[^,],%f,%d,%d", name, &overs, &runs, &wkts);
        float eco = overs > 0 ? runs / overs : 0;
        printf("| %-20s %-8.1f %-8d %-8d %-10.2f |\n", name, overs, runs, wkts, eco);

    }
    fclose(fball);

    FILE *fextra = fopen(extraFile, "r");
    int extras = 0;
    if (fextra) 
    { 
        fscanf(fextra, "%d", &extras); 
        fclose(fextra); 
    }

    printf("--------------------------------------------------------------\n");
    printf("| Extras: %-50d |\n", extras);
    printf("==============================================================\n\n");
}


// --- Ball & Bat Animation Functions ---
void printAt(int x, int y, char c) 
{
    printf("\033[%d;%dH%c", y, x, c);
    fflush(stdout);
}

void drawBat(int x, int topY) 
{
    for (int i = 0; i < 3; i++)
    { 
        printAt(x, topY + i, '|');       // Handle
    }
    for (int i = 3; i < 7; i++) 
    {                                 
        printAt(x - 1, topY + i, '#');      // Bottom
        printAt(x, topY + i, '#');
        printAt(x + 1, topY + i, '#');
    }
}

void animateBall() 
{
    //system("cls");       // Clear screen for animation
    int batX = 40, batTopY = 9;
    drawBat(batX, batTopY);

    int x = 10, y = 14, prevx, prevy;
    for (int i = 0; i < 28; i++) 
    {
        printAt(x, y, 'O');        // Ball
        Sleep(150);                // Speed 150ms
        prevx = x; prevy = y;
        printAt(prevx, prevy, ' '); // Erase previous
        x += 1;
    }
    printAt(1, y+4, ' '); // Move cursor below animation
}



int main()
{
    int innings;
    
    // Variables to store match data for both innings
    int totalRuns1 = 0, totalRuns2 = 0;
    int totalWickets1 = 0, totalWickets2 = 0;
    float totalOvers1 = 0.0, totalOvers2 = 0.0;
    int extras1 = 0, extras2 = 0;

    for (innings = 1; innings <= 2; innings++)
    {
        printf("\n--- Enter data for Innings %d ---\n", innings);

        int batsmenCount, bowlersCount, extras;
        float totalOvers = 0.0;
        int totalWickets = 0;

        printf("Enter number of batsmen: ");
        scanf("%d", &batsmenCount);
        getchar();
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
                i--; 
                continue;
            }
            if (batsmen[i].balls == 0 && batsmen[i].runs > 0)
            {
                printf("Error: Runs scored with 0 balls is impossible!\n");
                i--; 
                continue;
            }
            if (batsmen[i].runs > batsmen[i].balls * 6)
            {
                printf("Error: %s scored %d runs in %d balls — impossible!\n",
                   batsmen[i].name, batsmen[i].runs, batsmen[i].balls);
                i--; 
                continue;
            }
            if (batsmen[i].runs > 400)
            {
                printf("Error: %s scored %d runs — individual score cannot exceed 400.\n",
                batsmen[i].name, batsmen[i].runs);
                i--; 
                continue;
            }

        }

        printf("\nEnter number of bowlers: ");
        scanf("%d", &bowlersCount);
        getchar();
        Bowler bowlers[bowlersCount];

        for (int i = 0; i < bowlersCount; i++)
    {
        while (1)  // Keep asking until valid input
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
                continue;
            }

            if (bowlers[i].overs == 0 && (bowlers[i].runs_given > 0 || bowlers[i].wickets > 0))
            {
                printf("Error: Cannot concede runs or take wickets without bowling.\n");
                continue;
            }

            int whole = (int)bowlers[i].overs;
            int balls = (int)round((bowlers[i].overs - whole) * 10);
            if (balls > 5)
            {
                printf("Error: Invalid overs (%.1f) — fractional part cannot exceed .5 (6 balls).\n", bowlers[i].overs);
                continue;
            }

            if (bowlers[i].wickets > 10)
            {
                printf("Error: A bowler cannot take more than 10 wickets. Enter again.\n");
                continue;
            }

            if (totalOvers + bowlers[i].overs > 50.0)
            {
                printf("Error: Total overs exceed 50 (%.1f so far).\n", totalOvers + bowlers[i].overs);
                continue;
            }

            if (totalWickets + bowlers[i].wickets > 10)
            {
                printf("Error: Total wickets exceed 10 after adding this bowler (%d so far).\n", totalWickets + bowlers[i].wickets);
                continue;
            }
            int ballsBowled = whole * 6 + balls;
            if (bowlers[i].wickets > ballsBowled)
            {
                printf("Error: %s cannot take %d wickets in %.1f overs (%d balls).\n",
                bowlers[i].name, bowlers[i].wickets, bowlers[i].overs, ballsBowled);
                continue;
            }

            // If all checks pass, update totals and break the while loop
            totalOvers += bowlers[i].overs;
            totalWickets += bowlers[i].wickets;
            break;
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

        writeData(batsmen, batsmenCount, bowlers, bowlersCount, extras, innings);
        printf("\nData recorded successfully!");
        printf("\nTotal Team Score (Innings %d): %d/%d in %.1f overs\n", innings, totalRuns, totalWickets, totalOvers);
        displayData(innings);
        
        // For concluding statement comparison
        if (innings == 1)
        {
            totalRuns1 = totalRuns;
            totalWickets1 = totalWickets;
            totalOvers1 = totalOvers;
            extras1 = extras;
        }
        else
        {
            totalRuns2 = totalRuns;
            totalWickets2 = totalWickets;
            totalOvers2 = totalOvers;
            extras2 = extras;
        }
    }

    // Concluding Statement
    printf("\n--- Match Result ---\n");
    if (totalRuns1 > totalRuns2)
        printf("Team 1 wins by %d runs!\n", totalRuns1 - totalRuns2);
    else if (totalRuns2 > totalRuns1)
        printf("Team 2 wins by %d runs!\n", totalRuns2 - totalRuns1);
    else
        printf("The match is a tie!\n");

    printf("\n\n\n\n\n");  

    animateBall();

    return 0;
}