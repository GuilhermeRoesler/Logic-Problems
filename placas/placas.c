#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../souls.h"

void check_old_brasilian_standard(const char* placa) {
    int valido = 1;

    for (int i = 0; i < 3; i++) {
        if (!isupper(placa[i])) {
            valido = 0;
            break;
        }
    }

    if (placa[3] != '-') {
        valido = 0;
    }

    for (int i = 4; i < 8; i++) {
        if (!isdigit(placa[i])) {
            valido = 0;
            break;
        }
    }

    if (valido == 1) {
        printf("1\n");
    }
}

void check_mercosul_standard(const char* placa) {
    int valido = 1;

    for (int i = 0; i < 3; i++) {
        if (!isupper(placa[i])) {
            valido = 0;
            break;
        }
    }

    if (!isdigit(placa[3])) {
        valido = 0;
    }

    if (!isupper(placa[4])) {
        valido = 0;
    }

    for (int i = 5; i < 7; i++) {
        if (!isdigit(placa[i])) {
            valido = 0;
            break;
        }
    }

    if (valido == 1) {
        printf("2\n");
    }
}

int main() {
    char entrada[20];
    scanf("%s", entrada);

    int len = strlen(entrada);

    if (len == 8) {
        check_old_brasilian_standard(entrada);
    }
    else if (len == 7) {
        check_mercosul_standard(entrada);
    }
    else {
        printf("0\n");
    }
    return 0;
}