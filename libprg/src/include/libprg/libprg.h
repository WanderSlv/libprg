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

pilha_t* criarPilha(pilha_t* pilha, int capacidade);
int pilha_cheia(pilha_t* pilha);
int empilhar(pilha_t* pilha, int valor);
int desempilha(pilha_t* pilha);
int tamanho(pilha_t* pilha);
void destruir(pilha_t* pilha);
int topo(pilha_t* pilha);

// ---------- Fila ----------
typedef struct fila {
    int* elementos;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
}fila_t;

fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
bool cheia(fila_t* fila);
bool vazia(fila_t* fila);
int desenfileirar(fila_t* fila);
int tamanho_fila(fila_t* fila);
int inicio_fila(fila_t* fila);
int fim_fila(fila_t* fila);
void destruir_fila(fila_t* fila);

// ---------- Lista Linear ----------
typedef struct lista_linear {
    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_linear_t;

lista_linear_t* criar_lista_linear(int capacidade, bool ordenada);
void inserir_lista_linear(lista_linear_t* lista, int valor);
int buscar_lista(lista_linear_t* lista, int valor);
void remover_lista(lista_linear_t* lista, int valor);
bool cheia_lista_linear(lista_linear_t* lista);
bool vazia_lista_linear(lista_linear_t* lista);
void destruir_lista_linear(lista_linear_t* lista);
int tamanho_lista_linear(lista_linear_t* lista);
int* elementos_lista_linear(lista_linear_t* lista);
void imprimir_lista_linear(lista_linear_t* lista);

// ---------- Lista Ordenada ----------
typedef struct lista_ordenada lista_ordenada_t;


// ---------- Lista Encadeada ----------
typedef struct no no_t;
no_t* crar_lista_encadeada(int valor);

#endif
