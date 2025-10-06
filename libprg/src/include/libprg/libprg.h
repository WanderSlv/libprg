#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>

// ---------- Resultados ----------
typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

// ---------- Pilha ----------
typedef struct pilha {
    int* elementos;
    int topo;
    int capacidade;
} pilha_t;

pilha_t* criarPilha(int capacidade);
void pilha_cheia(pilha_t* pilha);
int empilhar(pilha_t* pilha);
int desempilha(pilha_t* pilha);
int tamanho(pilha_t* pilha);
void destruir(pilha_t* pilha);

// ---------- Fila ----------
typedef struct fila fila_t;

fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
bool cheia(fila_t* fila);
bool vazia(fila_t* fila);

// ---------- Lista Ordenada ----------
typedef struct lista_ordenada lista_ordenada_t;


// ---------- Lista Encadeada ----------
typedef struct no no_t;
no_t* crar_lista_encadeada(int valor);

#endif
