#ifndef SOULS_H
#define SOULS_H

#include <stdbool.h>
#include <stdint.h> // Necessário para uintptr_t

// ==========================================
// PROTÓTIPOS
// ==========================================

// Escalares
void print_int(int val);
void print_long(long long val);
void print_unsigned(unsigned long long val);
void print_double(double val);
void print_char(char val);
void print_string(const char* val);
void print_bool(_Bool val);
void print_pointer(void* val);
void print_newline();

// Arrays (1D)
void print_array_int(int* arr, int size);
void print_array_double(double* arr, int size);
void print_array_float(float* arr, int size);

// Matrizes (2D)
void print_matrix_int(int* arr, int rows, int cols);
void print_matrix_double(double* arr, int rows, int cols);
void print_matrix_float(float* arr, int rows, int cols);

// ==========================================
// MACRO MESTRA: SELETOR DE ARGUMENTOS
// ==========================================

#define ARG_COUNT(...) ARG_COUNT_(__VA_ARGS__, 4, 3, 2, 1, 0)
#define ARG_COUNT_(_1, _2, _3, _4, N, ...) N

#define print(...) PRINT_DISPATCHER(ARG_COUNT(__VA_ARGS__), __VA_ARGS__)
#define PRINT_DISPATCHER(n, ...) PRINT_DISPATCHER_(n, __VA_ARGS__)
#define PRINT_DISPATCHER_(n, ...) PRINT_##n(__VA_ARGS__)

// ==========================================
// IMPLEMENTAÇÃO COM CASTS DE PROTEÇÃO
// ==========================================

// O uso de (type*)(uintptr_t)(x) engana o compilador nos ramos não usados
// permitindo que 'double' ou 'char*' sejam ignorados nos ramos de 'int*' sem erro.

// CASO 1: Escalar simples
#define PRINT_1(x) _Generic((x), \
    _Bool:              print_bool,          \
    char:               print_char,          \
    signed char:        print_char,          \
    int:                print_int,           \
    long:               print_long,          \
    long long:          print_long,          \
    unsigned:           print_unsigned,      \
    unsigned long:      print_unsigned,      \
    unsigned long long: print_unsigned,      \
    float:              print_double,        \
    double:             print_double,        \
    long double:        print_double,        \
    char*:              print_string,        \
    const char*:        print_string,        \
    default:            print_pointer        \
)(x)

// CASO 2: Array OU Sequência
// Adicionado cast (type*)(uintptr_t) para evitar erro de compilação
// quando arg1 é char* ou double (ramos não selecionados).
#define PRINT_2(arg1, arg2) _Generic((arg1), \
    int*:       print_array_int((int*)(uintptr_t)(arg1), arg2),       \
    float*:     print_array_float((float*)(uintptr_t)(arg1), arg2),   \
    double*:    print_array_double((double*)(uintptr_t)(arg1), arg2), \
    default:    (PRINT_1(arg1), print_newline(), PRINT_1(arg2)) \
)

// CASO 3: Matriz OU Sequência
#define PRINT_3(arg1, arg2, arg3) _Generic((arg1), \
    int*:       print_matrix_int((int*)(uintptr_t)(arg1), arg2, arg3),       \
    float*:     print_matrix_float((float*)(uintptr_t)(arg1), arg2, arg3),   \
    double*:    print_matrix_double((double*)(uintptr_t)(arg1), arg2, arg3), \
    default:    (PRINT_1(arg1), print_newline(), PRINT_1(arg2), print_newline(), PRINT_1(arg3)) \
)

// CASO 4: Sequência pura
#define PRINT_4(arg1, arg2, arg3, arg4) \
    (PRINT_1(arg1), print_newline(), PRINT_1(arg2), print_newline(), PRINT_1(arg3), print_newline(), PRINT_1(arg4))

#endif // SOULS_H