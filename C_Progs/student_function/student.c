#include<stdio.h>
char getgrade(int marks)
{
    char grade;

    if(marks>=90)
        grade = 'A';
    else if(marks>=80)
        grade = 'B';
    else if(marks>=70)
        grade = 'C';
    else if(marks>=60)
        grade = 'D';
    else if(marks>=35)
        grade = 'E';
    else
        grade = 'F';

    return grade;
}

int main()
{
    float maths, chem, phys, eng, cs, avg;
    char mathgrd, chemgrd, physgrd, enggrd, csgrd;
    
    printf("Enter marks for students for all five subjects");
    scanf("%f %f %f %f %f", &maths, &chem, &phys, &eng, &cs); 

    avg = (maths+chem+phys+eng+cs)/5;
    printf("The average of all 5 subjects is %f \n", avg);

    mathgrd = getgrade(maths);
    chemgrd = getgrade(chem);
    physgrd = getgrade(phys);
    enggrd = getgrade(eng);
    csgrd = getgrade(cs);

    printf("Grades for all subjects are as follows Maths = %c \n"
           "Chemistry = %c \n Physics = %c \n English = %c \n" 
           "Computer science = %c \n", mathgrd, chemgrd, physgrd, enggrd, csgrd);
}