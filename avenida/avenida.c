#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int D;
    scanf("%d", &D);

    int multiplo = (int)round((double)D / 400.0) * 400;
    int resultado = abs(D - multiplo);

    printf("%d", resultado);

    return 0;
}

/*

int i = 0;
int penultima_distancia = 0;
int ultima_distancia = 0;

while (penultima_distancia >= ultima_distancia) {
    if (i == 0) {
        ultima_distancia = abs(i - D);
        penultima_distancia = ultima_distancia;
        i += 400;
        continue;
    }

    penultima_distancia = ultima_distancia;
    ultima_distancia = abs(i - D);
    i += 400;
}

printf("%d\n", penultima_distancia);

*/