#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../souls.h"

int get_vizinhos_vivos(int N, int matriz[N][N], int i, int j) {
    int vivos = 0;
    int posicoes[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    for (int k = 0; k < 8; k++) {
        int ni = i + posicoes[k][0];
        int nj = j + posicoes[k][1];

        if (ni >= 0 && ni < N && nj >= 0 && nj < N && matriz[ni][nj] == 1) {
            vivos++;
        }
    }

    return vivos;
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    int matriz[N][N];

    for (int j = 0; j < N; j++) {
        char input[N];
        scanf("%s", input);

        for (int i = 0; i < N; i++) {
            matriz[j][i] = input[i] - '0';
        }
    }

    int nova_matriz[N][N];
    for (int q = 0; q < Q; q++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int vizinhos_vivos = get_vizinhos_vivos(N, matriz, i, j);
                if (matriz[i][j] == 1) {
                    if (vizinhos_vivos == 2 || vizinhos_vivos == 3) {
                        nova_matriz[i][j] = 1;
                    }
                    else {
                        nova_matriz[i][j] = 0;
                    }
                }
                else {
                    if (vizinhos_vivos == 3) {
                        nova_matriz[i][j] = 1;
                    }
                    else {
                        nova_matriz[i][j] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matriz[i][j] = nova_matriz[i][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", nova_matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}