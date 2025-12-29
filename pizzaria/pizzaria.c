#include <stdio.h>

int main()
{
    int G, P;
    scanf("%d%d", &G, &P);

    printf("%d\n", G * 8 + P * 4 - 2);

    return 0;
}