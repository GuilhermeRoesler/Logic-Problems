#include <stdio.h>
#include "../souls.h"

int get_potencial(int N, int vetor[N]) {
    int accumulator = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j == i) {
                continue;
            }
            int resultado = vetor[i] * 10 + vetor[j];
            accumulator += resultado;
        }
    }
    return accumulator;
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    int lista[5];
    for (int i = 0; i < N; i++) {
        scanf("%d", &lista[i]);
    }

    int potenciais[Q];
    for (int i = 0; i < Q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        int len = y - x + 1;
        int vetor[len];
        for (int j = 0; j < len; j++) {
            vetor[j] = lista[x - 1 + j];
        }

        potenciais[i] = get_potencial(len, vetor);
    }

    for (int i = 0; i < Q; i++) {
        printf("%d\n", potenciais[i]);
    }

    return 0;
}