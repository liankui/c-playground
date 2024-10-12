#include <stdio.h>

int main() 
{
    int age = 29;
    int *pAge = &age;

    printf("%d\n", age);
    printf("%p\n", pAge);
    printf("%d\n", *pAge);
    printf("%p\n", &*pAge);
}

/*
29
0x7ff7bd1e016c
29
0x7ff7bd1e016c
*/