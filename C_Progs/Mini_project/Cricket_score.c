#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 50

typedef struct {
    char name[MAX];
    int runs;
    int balls;
} Batsman;

typedef struct {
    char name[MAX];
    float overs;
    int runs_given;
    int wickets;
} Bowler;

void writeData(Batsman batsmen[], int batsmenCount, Bowler bowlers[], int bowlersCount, int extras) {
    FILE *fbats = fopen("batsmen.txt", "w");
    if (!fbats) {
        printf("Error opening batsmen.txt\n");
        exit(1);
    }
    for (int i = 0; i < batsmenCount; i++) {
        fprintf(fbats, "%s,%d,%d\n", batsmen[i].name, batsmen[i].runs, batsmen[i].balls);
    }
    fclose(fbats);

    FILE *fball = fopen("bowlers.txt", "w");
    if (!fball) {
        printf("Error opening bowlers.txt\n");
        exit(1);
    }
    for (int i = 0; i < bowlersCount; i++) {
        fprintf(fball, "%s,%.1f,%d,%d\n", bowlers[i].name, bowlers[i].overs, bowlers[i].runs_given, bowlers[i].wickets);
    }
    fclose(fball);

    FILE *fextra = fopen("extras.txt", "w");
    if (!fextra) {
        printf("Error opening extras.txt\n");
        exit(1);
    }
    fprintf(fextra, "%d", extras);
    fclose(fextra);

    FILE *fdate = fopen("datetime.txt", "w");
    if (!fdate) {
        printf("Error opening datetime.txt\n");
        exit(1);
    }
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(fdate, "%04d-%02d-%02d %02d:%02d:%02d\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    fclose(fdate);
}

void displayData() {
    char line[100];

    printf("\n--- Cricket Match Summary ---\n\n");

    FILE *fdate = fopen("datetime.txt", "r");
    if (fdate == NULL) {
        printf("Error opening datetime.txt\n");
        return;
    }
    if (fgets(line, sizeof(line), fdate) != NULL) {
        printf("Match Date & Time: %s\n", line);
    }
    fclose(fdate);

    printf("Batsmen Performance:\n");
    printf("%-20s %-5s %-5s %-12s\n", "Name", "Runs", "Balls", "Strike Rate");
    FILE *fbats = fopen("batsmen.txt", "r");
    if (fbats == NULL) {
        printf("Error opening batsmen.txt\n");
        return;
    }
    while (fgets(line, sizeof(line), fbats) != NULL) {
        char name[MAX];
        int runs, balls;
        sscanf(line, "%[^,],%d,%d", name, &runs, &balls);
        float strike_rate = balls > 0 ? ((float)runs / balls) * 100 : 0.0;
        printf("%-20s %-5d %-5d %-12.2f\n", name, runs, balls, strike_rate);
    }
    fclose(fbats);

    printf("\nBowlers Performance:\n");
    printf("%-20s %-5s %-5s %-7s %-8s\n", "Name", "Overs", "Runs", "Wickets", "Economy");
    FILE *fball = fopen("bowlers.txt", "r");
    if (fball == NULL) {
        printf("Error opening bowlers.txt\n");
        return;
    }
    while (fgets(line, sizeof(line), fball) != NULL) {
        char name[MAX];
        float overs;
        int runs_given, wickets;
        sscanf(line, "%[^,],%f,%d,%d", name, &overs, &runs_given, &wickets);
        float economy = overs > 0 ? runs_given / overs : 0.0;
        printf("%-20s %-5.1f %-5d %-7d %-8.2f\n", name, overs, runs_given, wickets, economy);
    }
    fclose(fball);

    FILE *fextra = fopen("extras.txt", "r");
    if (fextra == NULL) {
        printf("Error opening extras.txt\n");
        return;
    }
    int extras;
    fscanf(fextra, "%d", &extras);
    fclose(fextra);
    printf("\nExtras: %d\n", extras);
}

int main() {
    int batsmenCount, bowlersCount, extras;

    printf("Enter number of batsmen: ");
    scanf("%d", &batsmenCount);
    getchar(); // consume newline

    Batsman batsmen[batsmenCount];
    for (int i = 0; i < batsmenCount; i++) {
        printf("\nEnter details for Batsman %d\n", i+1);
        printf("Name: ");
        fgets(batsmen[i].name, MAX, stdin);
        batsmen[i].name[strcspn(batsmen[i].name, "\n")] = 0; // remove newline

        printf("Runs scored: ");
        scanf("%d", &batsmen[i].runs);
        printf("Balls faced: ");
        scanf("%d", &batsmen[i].balls);
        getchar(); // consume newline
    }

    printf("\nEnter number of bowlers: ");
    scanf("%d", &bowlersCount);
    getchar(); // consume newline

    Bowler bowlers[bowlersCount];
    for (int i = 0; i < bowlersCount; i++) {
        printf("\nEnter details for Bowler %d\n", i+1);
        printf("Name: ");
        fgets(bowlers[i].name, MAX, stdin);
        bowlers[i].name[strcspn(bowlers[i].name, "\n")] = 0; // remove newline

        printf("Overs bowled: ");
        scanf("%f", &bowlers[i].overs);
        printf("Runs given: ");
        scanf("%d", &bowlers[i].runs_given);
        printf("Wickets taken: ");
        scanf("%d", &bowlers[i].wickets);
        getchar(); // consume newline
    }

    printf("\nEnter extras: ");
    scanf("%d", &extras);

    // Write all input data to files
    writeData(batsmen, batsmenCount, bowlers, bowlersCount, extras);

    // Display stored match summary
    displayData();

    return 0;
}