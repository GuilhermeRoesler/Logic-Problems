#include <stdio.h>
#include "../souls.h"

void permutar_linha(int N, int M, int matriz[N][M], int linha1, int linha2) {
    for (int i = 0; i < M; i++) {
        int temp[M];
        temp[i] = matriz[linha1 - 1][i];
        matriz[linha1 - 1][i] = matriz[linha2 - 1][i];
        matriz[linha2 - 1][i] = temp[i];
    }
}

void permutar_coluna(int N, int M, int matriz[N][M], int coluna1, int coluna2) {
    for (int i = 0; i < N; i++) {
        int temp[N];
        temp[i] = matriz[i][coluna2 - 1];
        matriz[i][coluna2 - 1] = matriz[i][coluna1 - 1];
        matriz[i][coluna1 - 1] = temp[i];
    }
}

int main() {
    int N, M, P;
    scanf("%d %d %d", &N, &M, &P);

    int matriz[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matriz[i][j] = i * M + j + 1;
        }
    }

    int ordens[P][3];
    char tipo;

    for (int i = 0; i < P; i++) {
        scanf(" %c %d %d", &tipo, &ordens[i][1], &ordens[i][2]);
        ordens[i][0] = tipo;
    }

    for (int i = 0; i < P; i++) {
        if (ordens[i][0] == 67) {
            permutar_coluna(N, M, matriz, ordens[i][1], ordens[i][2]);
        }
        else if (ordens[i][0] == 76) {
            permutar_linha(N, M, matriz, ordens[i][1], ordens[i][2]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
