#include <stdio.h>
#include <stdlib.h>
#include "../souls.h"

int comparar(const void* a, const void* b) {
    // Converte os ponteiros void* para ponteiros int* e compara os valores
    return (*(int*)b - *(int*)a);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int notas[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &notas[i]);
    }

    qsort(notas, N, sizeof(int), comparar);

    printf("%d\n", notas[K - 1]);

    return 0;
}