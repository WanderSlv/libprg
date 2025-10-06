//
// Created by wander on 25/09/2025.
//
#include <stdlib.h>

#include "stdbool.h"


typedef struct no {
    int valor;
    struct no* proximo;
}no_t;

no_t* criar_lista_encadeada(int valor) {
    no_t* no = (no_t*) malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = NULL;
    return no;
}

void adicionar_circular(no_t** inicio, int valor) {
    no_t* novo_no = criar_lista_encadeada(valor);
    novo_no->proximo = *inicio;
    *inicio = novo_no;
}



// no main
// int main () {
    // no_t*
    // adicionar(&lista_encadeada, 3);
    // return 0;
// }