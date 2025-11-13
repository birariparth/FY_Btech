#include <stdio.h>
#include <string.h>

struct Driver
{
    char name[50];
    char car[50];
    int driver_number;
    int podiums_2024;
    int podiums_2023;
    int points_2024;
    int points_2023;
};

void data(int driver_number, int year)
{
    // Predefined data for each driver
    struct Driver drivers[] =
    {
        {"Max Verstappen", "Red Bull", 1, 10, 15, 250, 350},
        {"Fernando Alonso", "Aston Martin", 14, 6, 12, 150, 220},
        {"Logan Sargeant", "Williams", 2, 0, 0, 0, 0},
        {"Alexander Albon", "Williams", 23, 1, 4, 25, 50},
        {"Zhou Guanyu", "Alfa Romeo", 24, 2, 5, 30, 70},
        {"Nico Hülkenberg", "Haas", 27, 1, 2, 15, 30},
        {"Daniel Ricciardo", "AlphaTauri", 3, 0, 3, 0, 30},
        {"Esteban Ocon", "Alpine", 31, 3, 7, 45, 85},
        {"George Russell", "Mercedes", 63, 9, 8, 225, 120},
        {"Lando Norris", "McLaren", 4, 5, 9, 125, 150},
        {"Lewis Hamilton", "Mercedes", 44, 15, 16, 230, 250},
        {"Sebastian Vettel", "Aston Martin", 5, 0, 2, 0, 30},
        {"Charles Leclerc", "Ferrari", 16, 7, 11, 175, 195},
        {"Lance Stroll", "Aston Martin", 18, 2, 4, 25, 60},
        {"Kevin Magnussen", "Haas", 20, 1, 3, 15, 40},
        {"Yuki Tsunoda", "AlphaTauri", 22, 1, 2, 15, 25},
        {"Sergio Pérez", "Red Bull", 11, 8, 10, 200, 180},
        {"Pierre Gasly", "Alpine", 10, 4, 6, 60, 75},
        {"Valtteri Bottas", "Alfa Romeo", 17, 1, 3, 15, 35},
        {"Oscar Piastri", "McLaren", 81, 6, 2, 150, 40}
    };

    struct Driver selected_driver = drivers[driver_number - 1];

    // Display driver's info based on the selected year
    printf("\nDriver: %s\n", selected_driver.name);
    printf("Car: %s\n", selected_driver.car);
    printf("Driver Number: %d\n", selected_driver.driver_number);
   
    // Display podium and points for the selected year
    if (year == 2024)
    {
        printf("Podiums in 2024: %d\n", selected_driver.podiums_2024);
        printf("Points scored in 2024: %d\n", selected_driver.points_2024);
    } else if (year == 2023)
    {
        printf("Podiums in 2023: %d\n", selected_driver.podiums_2023);
        printf("Points scored in 2023: %d\n", selected_driver.points_2023);
    } else
    {
        printf("Data not available for the year %d.\n", year);
    }
}

int main()
{
    int driver_number, year;

    label_input: // label to jump back if input invalid
    printf("\nDriver Number and Name List:\n");
    printf("1. Max Verstappen - 1\n");
    printf("2. Fernando Alonso - 14\n");
    printf("3. Logan Sargeant - 2\n");
    printf("4. Alexander Albon - 23\n");
    printf("5. Zhou Guanyu - 24\n");
    printf("6. Nico Hülkenberg - 27\n");
    printf("7. Daniel Ricciardo - 3\n");
    printf("8. Esteban Ocon - 31\n");
    printf("9. George Russell - 63\n");
    printf("10. Lando Norris - 4\n");
    printf("11. Lewis Hamilton - 44\n");
    printf("12. Sebastian Vettel - 5\n");
    printf("13. Charles Leclerc - 16\n");
    printf("14. Lance Stroll - 18\n");
    printf("15. Kevin Magnussen - 20\n");
    printf("16. Yuki Tsunoda - 22\n");
    printf("17. Sergio Pérez - 11\n");
    printf("18. Pierre Gasly - 10\n");
    printf("19. Valtteri Bottas - 17\n");
    printf("20. Oscar Piastri - 81\n");

    printf("\nEnter the driver number (1-20): ");
    if (scanf("%d", &driver_number) != 1 || driver_number < 1 || driver_number > 20)
    {
        printf("Invalid input! Please enter a valid driver number.\n");
        while(getchar() != '\n'); // clear buffer
        goto label_input; // Jump back to input
    }

    printf("Enter the year (2023 or 2024): ");
    if (scanf("%d", &year) != 1 || (year != 2023 && year != 2024))
    {
        printf("Invalid input! Please enter a valid driver number.\n");
        while(getchar() != '\n'); // clear buffer
        goto label_input; // Jump back to input
    }

    // Call the data function with the input values
    data(driver_number, year);

    return 0;
}