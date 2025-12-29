#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int fileira_1_index = 0;
    int fileira_1[K];
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        if (x) {
            fileira_1[fileira_1_index++] = i;
        }
    }

    int fileira_2_index = 0;
    int accumulator = 0;
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        if (x) {
            accumulator += abs(i - fileira_1[fileira_2_index++]);
        }
    }
    printf("%d\n", accumulator);

    return 0;
}