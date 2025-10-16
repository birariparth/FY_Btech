#include<stdio.h>
#include<string.h>

struct employee
{
    float sal;
    char name[50];
    long double id;
    long double number;
};

int main()
{
    int n, i, j;
    float temp;
    struct employee var;
   
    printf("Enter number of employees: ");
    scanf(" %d", &n);
   
    struct employee emp[n];
   
   
    for(i=0; i<n; i++)
    {
        printf("Enter Name %d employees: \n", i);
        scanf(" %s", &emp[i].name);
        printf("Enter ID %d employees: \n", i);
        scanf(" %Lf", &emp[i].id);
        printf("Enter contact details %d employees: \n", i);
        scanf(" %Lf", &emp[i].number);
        printf("Enter salaries %d employees: \n", i);
        scanf(" %f", &emp[i].sal);
    }
   
    //sorting the array
    /*for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(emp[i].sal > emp[i + 1].sal)
            {
                struct employee temp = emp[i];
                emp[i] = emp[i + 1];
                emp[i + 1] = temp;
            }
        }
    }*/
    printf("\n The sorted array is as follows \n");;
    for(i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("Name   : %s\n", emp[i].name);
        printf("ID     : %Lf\n", emp[i].id);
        printf("Contact: %Lf\n", emp[i].number);
        printf("Salary : %.2f\n", emp[i].sal);
    }
    return 0;
}