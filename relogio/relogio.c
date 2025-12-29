#include <stdio.h>
#include "../souls.h"

int main() {
    int H, M, S, T;
    scanf("%d", &H);
    scanf("%d", &M);
    scanf("%d", &S);
    scanf("%d", &T);

    S += T;
    int resto_S = S / 60;
    S = S % 60;

    M += resto_S;
    int resto_M = M / 60;
    M = M % 60;

    H += resto_M % 24;

    print(H);
    print(M);
    print(S);

    return 0;
}