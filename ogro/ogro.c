#include <stdio.h>

int main() {
    int E, D, resultado;
    scanf("%d", &E);
    scanf("%d", &D);

    if (E > D) {
        resultado = E + D;
    }
    else {
        resultado = 2 * (D - E);
    }

    printf("%d\n", resultado);
    return 0;
}