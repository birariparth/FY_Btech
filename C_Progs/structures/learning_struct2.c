#include <stdio.h>

struct stu
{
    char name[50];
    int age;
    float grade;
};

int main()
{
    struct stu s1 = {"Parth", 20, 99.9};

    struct stu s1c = s1;        //creates a copy of s1

    struct stu s2 = {.age = 18, .name = "praneel", .grade = 82.3};

    printf("%s \t %d \t %.2f \n", s1c.name, s1c.age, s1c.grade);
    printf("%s \t %d \t %.2f \t", s2.name, s2.age, s2.grade);
    return 0;
}