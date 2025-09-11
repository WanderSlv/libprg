//
// Created by wander on 11/09/2025.
//

//
// Created by wander on 26/08/2025.
//
#include "libprg/libprg.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    typedef struct pilha {
        int* elementos;
        int topo;
        int capacidade;
    } pilha_t;


pilha_t* criarPilha(int capacidade) {

    pilha_t* p = malloc (sizeof(pilha_t));
    p->elementos = malloc(capacidade * sizeof(int));
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

int empilhar(pilha_t *pilha, int valor) {

    if (pilha->topo == (pilha->capacidade +1)) {
        pilha->capacidade *= 2;
        pilha->elementos = realloc(pilha->elementos, pilha->capacidade * sizeof(int));
        // exit(EXIT_FAILURE);
    }

    pilha->topo++;
    pilha -> elementos[pilha->topo] = valor;
}



int tamanho(pilha_t* pilha) {
    return pilha->topo + 1;
}


void destruir(pilha_t* pilha) {
    free(pilha->elementos);
    free(pilha);
}