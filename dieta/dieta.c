#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);

    int P, G, C;
    int soma = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &P, &G, &C);
        soma += P * 4 + G * 9 + C * 4;
    }

    printf("%d\n", M - soma);

    return 0;
}