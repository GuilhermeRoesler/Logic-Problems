#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int soma = 0;
    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        int distancia = abs(x - y) > 5 ? 10 - abs(x - y) : abs(x - y);
        soma += distancia;
    }
    printf("%d\n", soma);

    return 0;
}