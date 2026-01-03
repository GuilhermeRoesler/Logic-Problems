#include <stdio.h>
#include <stdlib.h>

#define MAXN 200005

// Usamos long long para somas, pois podem exceder o limite de int (2 bilhões)
// p[i]: preço do dia i
long long p[MAXN];

// pref[i]: soma acumulada (prefix sum) de p[0] até p[i]
long long pref[MAXN];

// block_sum[i]: soma da janela de tamanho D terminando em i (custo dos dias i-D+1 até i)
long long block_sum[MAXN];

// Deque para encontrar o máximo no intervalo deslizante
// Armazena índices 'i' onde block_sum[i] é um candidato a melhor desconto
int q[MAXN];
int head = 0;
int tail = -1;

// Adiciona um índice ao final do deque, mantendo a ordem decrescente de valores
void push_back(int idx) {
    while (head <= tail && block_sum[q[tail]] <= block_sum[idx]) {
        tail--;
    }
    tail++;
    q[tail] = idx;
}

// Remove índices da frente do deque se eles saírem da janela válida [L, R]
// O limite aqui é o menor índice onde uma janela de tamanho D pode TERMINAR
// e ainda estar totalmente dentro do intervalo que começa em L.
// Ou seja, a janela termina em 'limit_idx', então ela começa em 'limit_idx - D + 1'.
// Se 'limit_idx - D + 1' < L, então 'limit_idx' < L + D - 1.
void pop_front_if_lower_than(int limit_idx) {
    if (head <= tail && q[head] < limit_idx) {
        head++;
    }
}

// Retorna o índice da janela com a maior soma (melhor desconto) no deque atual
int get_max_idx() {
    return q[head];
}

int main() {
    int N, D;
    long long W;

    // Leitura segura
    if (scanf("%d %d %lld", &N, &D, &W) != 3) return 0;

    for (int i = 0; i < N; i++) {
        scanf("%lld", &p[i]);
    }

    // 1. Pré-cálculo das somas de prefixo para calcular custo de intervalos em O(1)
    pref[0] = p[0];
    for (int i = 1; i < N; i++) {
        pref[i] = pref[i - 1] + p[i];
    }

    // 2. Pré-cálculo das somas de todas as janelas possíveis de tamanho D (candidatos a desconto)
    // block_sum[i] só é válido para i >= D-1
    for (int i = D - 1; i < N; i++) {
        long long current_block = pref[i];
        if (i - D >= 0) {
            current_block -= pref[i - D];
        }
        block_sum[i] = current_block;
    }

    int max_days = 0;
    int L = 0;

    // 3. Algoritmo de Dois Ponteiros (Sliding Window)
    // R (fim das férias) avança de D-1 até N-1. 
    // Começamos em D-1 pois o tamanho mínimo das férias é D (dias pagos).
    for (int R = D - 1; R < N; R++) {
        // Adiciona a nova opção de desconto (janela terminando em R)
        push_back(R);

        // Enquanto o custo do intervalo atual [L, R] for maior que W, encolhemos pela esquerda
        while (1) {
            // Custo total bruto do intervalo [L, R]
            long long total_cost = pref[R];
            if (L > 0) total_cost -= pref[L - 1];

            // Para validar o custo, precisamos subtrair o MELHOR desconto contido totalmente em [L, R].
            // Uma janela de desconto termina num índice 'idx'. Para estar dentro de [L, R]:
            // - O fim 'idx' deve ser <= R (garantido pelo loop for).
            // - O início 'idx - D + 1' deve ser >= L. Logo, idx >= L + D - 1.

            // Removemos do deque opções de desconto que começam ANTES de L
            pop_front_if_lower_than(L + D - 1);

            // Pega o melhor desconto válido
            int best_block_idx = get_max_idx();
            long long discount = block_sum[best_block_idx];

            long long final_cost = total_cost - discount;

            if (final_cost <= W) {
                // Intervalo válido (dinheiro suficiente)
                break;
            }
            else {
                // Dinheiro insuficiente: precisamos diminuir o tamanho das férias removendo dias do início
                L++;
            }
        }

        // Atualiza a resposta com o tamanho do intervalo atual
        int current_days = R - L + 1;
        if (current_days > max_days) {
            max_days = current_days;
        }
    }

    printf("%d\n", max_days);

    return 0;
}