#include <stdio.h>
#include <stdlib.h>
#include "../souls.h"

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int matriz[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    int matriz_final[2][3];

    for (int I = 0; I < N; I++) {
        for (int J = 0; J < M; J++) {
            int poder_maximo = matriz[I][J];

            int heroes_matriz[2][3];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (i == I && j == J) {
                        heroes_matriz[i][j] = 1;
                        continue;
                    }
                    heroes_matriz[i][j] = 0;
                }
            }

            int has_modified = 1;
            while (has_modified) {
                has_modified = 0;

                int available_options[N * M][3];
                int last_index = 0;
                int num_available = 0;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        if (heroes_matriz[i][j] == 1) {
                            available_options[last_index][0] = -1;
                            available_options[last_index][1] = -1;
                            available_options[last_index][2] = -1;
                            last_index++;
                            continue;
                        }
                        if (i - 1 >= 0 && heroes_matriz[i - 1][j] == 1) {
                            available_options[last_index][0] = matriz[i][j];
                            available_options[last_index][1] = i;
                            available_options[last_index][2] = j;
                            last_index++;
                            num_available++;
                            continue;
                        }
                        if (j - 1 >= 0 && heroes_matriz[i][j - 1] == 1) {
                            available_options[last_index][0] = matriz[i][j];
                            available_options[last_index][1] = i;
                            available_options[last_index][2] = j;
                            last_index++;
                            num_available++;
                            continue;
                        }
                        if (i + 1 < N && heroes_matriz[i + 1][j] == 1) {
                            available_options[last_index][0] = matriz[i][j];
                            available_options[last_index][1] = i;
                            available_options[last_index][2] = j;
                            last_index++;
                            num_available++;
                            continue;
                        }
                        if (j + 1 < M && heroes_matriz[i][j + 1] == 1) {
                            available_options[last_index][0] = matriz[i][j];
                            available_options[last_index][1] = i;
                            available_options[last_index][2] = j;
                            last_index++;
                            num_available++;
                            continue;
                        }
                        available_options[last_index][0] = -1;
                        available_options[last_index][1] = -1;
                        available_options[last_index][2] = -1;
                        last_index++;
                    }
                }

                while (num_available > 0) {
                    for (int i = 0; i < N * M; i++) {
                        int value = available_options[i][0];
                        if (value == -1) {
                            continue;
                        }
                        num_available--;
                        if (value <= poder_maximo) {
                            poder_maximo += value;
                            available_options[i][0] = -1;
                            has_modified = 1;
                            heroes_matriz[available_options[i][1]][available_options[i][2]] = 1;
                        }
                    }
                }
            }
            matriz_final[I][J] = poder_maximo;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matriz_final[i][j]);
        }
        printf("\n");
    }

    return 0;
}