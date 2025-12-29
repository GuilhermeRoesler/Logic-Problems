#include <stdio.h>
#include "souls.h"

// --- CORES ---
#define COLOR_RESET   "\x1b[0m"
#define COLOR_INT     "\x1b[34m" 
#define COLOR_FLOAT   "\x1b[35m" 
#define COLOR_CHAR    "\x1b[33m" 
#define COLOR_STRING  "\x1b[32m" 
#define COLOR_BOOL    "\x1b[36m" 
#define COLOR_ARRAY   "\x1b[37m"
#define COLOR_MATRIX  "\x1b[96m" // Ciano claro para matriz

// ==========================================
// AUXILIARES
// ==========================================
void print_newline() {
    // Apenas imprime um separador visual se imprimirmos varios itens
    // Não pulamos linha aqui para permitir composição, ou pulamos?
    // Vamos pular linha para ficar lista vertical limpa.
    // O print_1 já pula linha, então aqui não fazemos nada ou colocamos um prefixo?
    // O macro PRINT_1 já tem \n. Não precisamos adicionar mais nada.
    // Mas para garantir que funcione em sequencia, deixamos vazio.
}

// ==========================================
// ESCALAR (Mantidos iguais, simplificados para brevidade aqui)
// ==========================================

void print_int(int val) { printf(COLOR_INT "(int) %d" COLOR_RESET "\n", val); }
void print_long(long long val) { printf(COLOR_INT "(long) %lld" COLOR_RESET "\n", val); }
void print_unsigned(unsigned long long val) { printf(COLOR_INT "(unsigned) %llu" COLOR_RESET "\n", val); }
void print_double(double val) { printf(COLOR_FLOAT "(double) %.4f" COLOR_RESET "\n", val); }
void print_char(char val) { printf(COLOR_CHAR "(char) '%c'" COLOR_RESET "\n", val); }
void print_bool(_Bool val) { printf(COLOR_BOOL "(bool) %s" COLOR_RESET "\n", val ? "true" : "false"); }
void print_pointer(void* val) { printf("(void*) %p\n", val); }

void print_string(const char* val) {
    if (val == NULL) printf(COLOR_STRING "(string) NULL" COLOR_RESET "\n");
    else printf(COLOR_STRING "(string) \"%s\"" COLOR_RESET "\n", val);
}

// ==========================================
// ARRAYS 1D
// ==========================================

// print(array, M);
void print_array_int(int* arr, int size) {
    printf(COLOR_ARRAY "[");
    for (int i = 0; i < size; i++) printf("%d%s", arr[i], (i < size - 1) ? ", " : "");
    printf("]" COLOR_RESET "\n");
}

void print_array_double(double* arr, int size) {
    printf(COLOR_ARRAY "[");
    for (int i = 0; i < size; i++) printf("%.2f%s", arr[i], (i < size - 1) ? ", " : "");
    printf("]" COLOR_RESET "\n");
}

void print_array_float(float* arr, int size) {
    printf(COLOR_ARRAY "[");
    for (int i = 0; i < size; i++) printf("%.2f%s", arr[i], (i < size - 1) ? ", " : "");
    printf("]" COLOR_RESET "\n");
}

// ==========================================
// MATRIZES 2D
// Recebe ponteiro linear. Acesso: i * cols + j
// ==========================================

// print(&matriz[0][0], N, M);
void print_matrix_int(int* arr, int rows, int cols) {
    printf(COLOR_MATRIX "Matrix (%dx%d):\n" COLOR_RESET, rows, cols);
    for (int i = 0; i < rows; i++) {
        printf("  [");
        for (int j = 0; j < cols; j++) {
            printf("%d%s", arr[i * cols + j], (j < cols - 1) ? ", " : "");
        }
        printf("]\n");
    }
}

void print_matrix_double(double* arr, int rows, int cols) {
    printf(COLOR_MATRIX "Matrix (%dx%d):\n" COLOR_RESET, rows, cols);
    for (int i = 0; i < rows; i++) {
        printf("  [");
        for (int j = 0; j < cols; j++) {
            printf("%.2f%s", arr[i * cols + j], (j < cols - 1) ? ", " : "");
        }
        printf("]\n");
    }
}

void print_matrix_float(float* arr, int rows, int cols) {
    printf(COLOR_MATRIX "Matrix (%dx%d):\n" COLOR_RESET, rows, cols);
    for (int i = 0; i < rows; i++) {
        printf("  [");
        for (int j = 0; j < cols; j++) {
            printf("%.2f%s", arr[i * cols + j], (j < cols - 1) ? ", " : "");
        }
        printf("]\n");
    }
}