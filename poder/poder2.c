#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int matriz[N][M];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &matriz[i][j]);

    int matriz_final[N][M];

    for (int I = 0; I < N; I++) {
        for (int J = 0; J < M; J++) {
            int poder = matriz[I][J];
            int visitado[N][M];
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    visitado[i][j] = 0;

            // fila para BFS
            int fila[MAX][2], ini = 0, fim = 0;
            fila[fim][0] = I; fila[fim][1] = J; fim++;
            visitado[I][J] = 1;

            while (ini < fim) {
                int x = fila[ini][0], y = fila[ini][1];
                ini++;

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visitado[nx][ny]) {
                        if (matriz[nx][ny] <= poder) {
                            poder += matriz[nx][ny];
                            visitado[nx][ny] = 1;
                            fila[fim][0] = nx; fila[fim][1] = ny; fim++;
                        }
                    }
                }
            }
            matriz_final[I][J] = poder;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%d ", matriz_final[i][j]);
        printf("\n");
    }

    return 0;
}