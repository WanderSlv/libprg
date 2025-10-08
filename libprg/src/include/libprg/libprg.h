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
void inserir_lista_linear(lista_linear_t* lista_linear, int valor);
int buscar_lista(lista_linear_t* lista_linear, int valor);
void remover_lista(lista_linear_t* lista_linear, int valor);
bool cheia_lista_linear(lista_linear_t* lista_linear);
bool vazia_lista_linear(lista_linear_t* lista_linear);
void destruir_lista_linear(lista_linear_t* lista_linear);
int tamanho_lista_linear(lista_linear_t* lista_linear);
int* elementos_lista_linear(lista_linear_t* lista_linear);
void imprimir_lista_linear(lista_linear_t* lista_linear);

// ---------- Lista Ordenada ----------

typedef struct {
    int *elementos;
    int capacidade;
    int tamanho;
    bool ordenada;
} lista_ordenada_t;

// ====== DECLARAÇÃO DAS FUNÇÕES ======
lista_ordenada_t* criar_lista_ordenada(int capacidade, bool ordenada);
void inserir(lista_ordenada_t* lista, int valor);
void inserir_ordenada(lista_ordenada_t* lista, int valor);
void inserir_nao_ordenada(lista_ordenada_t* lista, int valor);
int buscar(lista_ordenada_t* lista, int valor);
bool lista_vazia(lista_ordenada_t* lista);
bool lista_cheia(lista_ordenada_t* lista);
void remover_elemento(lista_ordenada_t* lista, int valor);
void destruir_lista(lista_ordenada_t* lista);
void exibir_lista(lista_ordenada_t* lista);


// ---------- Lista Encadeada ----------

typedef struct no {
    int valor;
    struct no* proximo;
} No;

typedef struct {
    No* inicio;
    int tamanho;
} ListaEncadeada;

ListaEncadeada* criar_lista_encadeada();
void inserir_no_inicio(ListaEncadeada* lista, int valor);
void inserir_no_fim(ListaEncadeada* lista, int valor);
bool remover_elemento(ListaEncadeada* lista, int valor);
No* buscar_elemento(ListaEncadeada* lista, int valor);
void exibir_lista(ListaEncadeada* lista);
void destruir_lista_encadeada(ListaEncadeada* lista);


#endif
