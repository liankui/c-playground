#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    /* data */
    char name[50];
    char major[50];
    int age;
    double gpa;
};

int main() 
{
    struct Student student;
    student.age = 29;
    student.gpa = 4.1;
    strcpy(student.name, "eric");
    strcpy(student.major, "cs");

    printf("%s\n", student.name);
}
