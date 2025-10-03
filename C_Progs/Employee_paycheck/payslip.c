#include<stdio.h>

//Facial recognition ai camera
int main()
{
    int id, hours, wage, mansal, recepsal, workersal;
    char num[10];
    char name[50];
    char type;
    
    mansal = 2000;
    recepsal = 1500;
    workersal = 1000;
    
    printf("Scanning employee, fetching name: \n");
    scanf("%s", &name);
    printf("Fetching employee phone number: \n");
    scanf("%s", &num);
    printf("Fetching employee id: \n");
    scanf("%d", &id);
    printf("Calculating total hours worked in a day: \n");
    scanf("%d", &hours);
    printf("Fetching employee post(manager=m/receptionist=r/worker=w): \n");
    scanf(" %c", &type);
    
    printf("---------------------------------------------------------------------\n");
    printf("|                              Invoice                              |\n");
    printf("---------------------------------------------------------------------\n");
    printf("|\tEmployee name:%45s |\n", name);
    printf("|\tEmployee contact details:%34s |\n", num);
    printf("|\tEmployee id:%47d |\n", id);
    printf("|\tNumber of hours worked by employee today:%18d |\n", hours);
    
    if(type == 'm')
    {
        wage = hours*mansal;
        printf("|\tPost of employee:\t\t\t\t\t\t\t\t\t Manager    |\n");
        printf("|\tSalary as per hours worker is:\t\t\t\t\t%d \t        |\n", wage);
    }
    else if(type == 'r')
    {
        printf("|\tPost of employee:\t\t\t\t\t\t\t\tReceptionist \t|\n");
        wage = hours*recepsal;
        printf("|\tSalary as per hours worker is:\t\t\t\t\t%d \t        |\n", wage);
    }
    else if(type == 'w')
    {
        printf("|\tPost of employee:\t\t\t\t\t\t\t\t\t\t Worker |\n");
        wage = hours*workersal;
        printf("|\tSalary as per hours worker is:\t\t\t\t\t%d \t        |\n", wage);
    }
    else
    {
        printf("|\tEnter post donest exist \n");
    }
    printf("---------------------------------------------------------------------\n");
    return 0;
}
