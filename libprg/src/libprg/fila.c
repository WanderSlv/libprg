#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"


// criar fila
fila_t* criar_fila(int capacidade) {
    fila_t* f = malloc(sizeof(fila_t));
    f->elementos = malloc(sizeof(int) * capacidade);
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = capacidade;
    return f;
}

// enfileirar
void enfileirar(fila_t* fila, int valor) {
    if (!cheia(fila)) { // verifica se a fila esta
        fila->elementos[fila->fim] = valor;
        fila->fim = (fila->fim + 1) % fila->capacidade; // Fila circular é mais segura
        fila->tamanho++;
    }
}

//cheia
bool cheia(fila_t* fila) {
    return fila->tamanho == fila->capacidade;
}

// vazia
bool vazia(fila_t* fila) {
    return fila->tamanho == 0;
}

// next funcions