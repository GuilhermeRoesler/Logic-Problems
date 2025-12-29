#include <stdio.h>

int power_of(int N, int power) {
    int result = 1;
    for (int i = 0; i < power; i++) {
        result *= N;
    }
    return result;
}

int main() {
    int N;
    scanf("%d", &N);

    printf("%d\n", power_of(N - 2, 3));
    printf("%d\n", power_of(N - 2, 2) * 6);
    printf("%d\n", 12 * (N - 2));
    printf("8\n");

    return 0;
}