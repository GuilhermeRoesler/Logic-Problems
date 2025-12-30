#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r;
    int c;
} Coordenada;

int main() {
    int N;
    scanf("%d", &N);

    int capacidade = 10;
    int total_uns = 0;

    Coordenada* coords = (Coordenada*)malloc(capacidade * sizeof(Coordenada));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int valor;
            scanf("%1d", &valor);

            if (i <= j && valor == 1) {
                if (total_uns == capacidade) {
                    capacidade *= 2;
                    coords = (Coordenada*)realloc(coords, capacidade * sizeof(Coordenada));

                    if (coords == NULL) {
                        printf("Erro de memória\n");
                        return 1;
                    }
                }

                coords[total_uns].r = i + 1;
                coords[total_uns].c = j + 1;
                total_uns++;
            }
        }
    }

    int E;
    scanf("%d", &E);

    int founds[E];
    for (int i = 0; i < E; i++) {
        int quantidade;
        scanf("%d", &quantidade);

        int array[quantidade];

        for (int j = 0; j < quantidade; j++) {
            scanf("%d", &array[j]);
        }

        int found = 0;
        for (int j = 0; j < total_uns && !found; j++) {
            int encontradoA = 0;
            int encontradoB = 0;

            for (int k = 0; k < quantidade; k++) {
                if (array[k] == coords[j].r) {
                    encontradoA = 1;
                }
                if (array[k] == coords[j].c) {
                    encontradoB = 1;
                }
                if (encontradoA && encontradoB) {
                    found = 1;
                    break;
                }
            }
        }
        if (found) {
            founds[i] = 1;
        }
        else {
            founds[i] = 0;
        }
    }

    for (int i = 0; i < E; i++) {
        if (founds[i]) {
            printf("S\n");
        }
        else {
            printf("N\n");
        }
    }

    free(coords);

    return 0;
}