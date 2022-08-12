#include <stdio.h>

int main()
{
    char someString[18] = "hello world";
    char someCharArray[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};

    printf("%s\n", someString);
    printf("%c\n", someCharArray[0]);
}