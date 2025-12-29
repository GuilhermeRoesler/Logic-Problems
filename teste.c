#include <stdio.h>

int somar(int a, int b) {
    int resultado = a + b;
    return resultado;
}

int main() {
    int x = 10;
    int y = 20;
    int total = 0;

    printf("Iniciando o programa...\n");

    total = somar(x, y);

    printf("O total e: %d\n", total);
    return 0;
}

/*

int i = 0;
int antepenultima_distancia = 0;
int ultima_distancia = 0;

while (antepenultima_distancia >= ultima_distancia) {
    i += 400;

    if (i == 400) {
        ultima_distancia = abs(i - 720);
        antepenultima_distancia = ultima_distancia;
        continue;
    }

    antepenultima_distancia = ultima_distancia;
    ultima_distancia = abs(i - 720);
}

printf("%d\n", antepenultima_distancia);

*/