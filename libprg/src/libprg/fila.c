#include <stdlib.h>
#include <libprg/libprg.h>
#include <stdbool.h>

typedef struct fila {
    int* elementos;
    int tamanho, inicio, fim, capacidade;
} fila_t;

// criar fila

fila_t* criar_fila(int capacidade) {

    fila_t* f = malloc(sizeof(fila_t));
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = capacidade;

    return f;
}

// enfileirar

void enfileirar(fila_t* fila, int valor) {
    fila->elementos[fila->fim] = valor;
    fila -> fim++;
}

//cheia
bool cheia(fila_t* fila) {
    if (fila->tamanho >= fila->capacidade) {
        return true;
    } else {
        return false;
    }
}

// vazia
bool vazia(fila_t* fila) {
    if (fila->tamanho == 0) {
        return true;
    }
}

// desenfileirar
// inicio
// fim
// tamanho
// destruir