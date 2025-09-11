#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

//Fila
// Declaração da estrutura e do tipo fila_t
typedef struct fila {
    int* elementos;
    int tamanho, inicio, fim, capacidade;
} fila_t;

// Declaração (protótipos) das funções
fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
bool cheia(fila_t* fila);
bool vazia(fila_t* fila);

#endif
