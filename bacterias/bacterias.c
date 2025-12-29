#include <stdio.h>
#include "../souls.h"

int main() {
    int P, N;
    scanf("%d", &N);
    scanf("%d", &P);

    int dias = 0, bacterias = 1;
    while (bacterias <= N) {
        bacterias *= P;
        dias++;
    }
    dias--;

    print(dias);

    return 0;
}