#include <stdio.h>
#include <string.h>

int main() {
    int K, N;
    scanf("%d %d", &K, &N);

    char alfabeto[K + 1];
    scanf("%s", alfabeto);

    char mensagem[N + 1];
    scanf("%s", mensagem);

    for (int i = 0; i < N; i++) {
        if (strchr(alfabeto, mensagem[i]) == NULL) {
            printf("N\n");
            return 0;
        }
    }

    printf("S\n");
    return 0;
}

/*

int K, N;
scanf("%d %d", &K, &N);

char alfabeto[K + 1];
scanf("%s", alfabeto);

char mensagem[N + 1];
scanf("%s", mensagem);

for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
        if (mensagem[i] == alfabeto[j]) {
            break;
        }
        else if (j == K - 1) {
            printf("N\n");
            return 0;
        }
    }
}

printf("S\n");

return 0;

*/