#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"


// Criar lista
lista_ordenada_t* criar_lista_ordenada(int capacidade, bool ordenada) {
    lista_ordenada_t* lista = malloc(sizeof(lista_ordenada_t));
    lista->elementos = malloc(capacidade * sizeof(int));
    lista->capacidade = capacidade;
    lista->tamanho = 0;
    lista->ordenada = ordenada;
    return lista;
}

void inserir_ordenada(lista_ordenada_t * lista, int valor);

void inserir_nao_ordenada(lista_ordenada_t * lista, int valor);

// Inserir elemento (decide se é ordenada ou não)
void inserir(lista_ordenada_t* lista, int valor) {
    if (lista_cheia(lista)) {
        printf("Lista cheia!\n");
        return;
    }

    if (lista->ordenada) {
        inserir_ordenada(lista, valor);
    } else {
        inserir_nao_ordenada(lista, valor);
    }
}

// Inserção não ordenada (coloca no final)
void inserir_nao_ordenada(lista_ordenada_t* lista, int valor) {
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}

// Inserção ordenada (mantém ordem crescente)
void inserir_ordenada(lista_ordenada_t* lista, int valor) {
    int i = lista->tamanho - 1;

    // desloca elementos maiores que "valor" para a direita
    while (i >= 0 && lista->elementos[i] > valor) {
        lista->elementos[i + 1] = lista->elementos[i];
        i--;
    }

    // insere o valor na posição correta
    lista->elementos[i + 1] = valor;
    lista->tamanho++;
}

// Buscar elemento
int buscar(lista_ordenada_t* lista, int valor) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == valor) {
            return i;
        }
    }
    return -1;
}

// Remover elemento
bool remover_elemento_ord(lista_ordenada_t* lista, int valor) {
    int pos = buscar(lista, valor);
    if (pos == -1) {
        printf("Elemento não encontrado!\n");
        return false; // CORREÇÃO: Retorna 'false' quando não encontra
    }

    // Desloca os elementos
    for (int i = pos; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }

    lista->tamanho--;
    printf("Elemento %d removido com sucesso!\n", valor);
    return true; // CORREÇÃO: Retorna 'true' no sucesso
}

// Verifica se a lista está cheia
bool lista_cheia(lista_ordenada_t* lista) {
    return lista->tamanho >= lista->capacidade;
}

// Verifica se a lista está vazia
bool lista_vazia(lista_ordenada_t* lista) {
    return lista->tamanho == 0;
}

// Exibir todos os elementos
void exibir_lista_ord(lista_ordenada_t* lista) {
    printf("[");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d", lista->elementos[i]);
        if (i < lista->tamanho - 1)
            printf(", ");
    }
    printf("]\n");
}

void destruir_lista_ordenada(lista_ordenada_t* lista) { // Renomeada
    if (lista != NULL) {
        if (lista->elementos != NULL) {
            free(lista->elementos);
        }
        free(lista);
    }
}