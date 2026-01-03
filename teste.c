#include <stdio.h>
#include "./souls.h"

int main() {
    Vetor v;
    initVetor(&v);

    // adicionando elementos
    for (int i = 0; i < 10; i++) {
        pushBack(&v, i * 10);
    }

    // imprimindo
    showVetor(&v);

    freeVetor(&v);
    return 0;
}
