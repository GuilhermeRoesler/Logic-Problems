#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int ordem[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &ordem[i]);
    }

    int ranking[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (ordem[j] == i + 1) {
                ranking[i] = j + 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", ranking[i]);
    }

    return 0;
}