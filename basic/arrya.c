#include <stdio.h>

int main()
{
    int numbers[] = {1,2,3,4,5,6};
    int numbers2[6];

    numbers2[0] = 1;
    numbers2[1] = 2;

    printf("%d\n", numbers[1]);
    printf("%d\n", numbers2[1]);
    return 0;
}