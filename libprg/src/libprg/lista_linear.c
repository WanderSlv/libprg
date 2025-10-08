#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"

void inserir_ordenada(lista_linear_t* lista, int valor);
void inserir_nao_ordenada(lista_linear_t* lista, int valor);

lista_linear_t* criar_lista_linear(int capacidade, bool ordenada) {
    lista_linear_t* lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int) * capacidade);
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    lista->ordenada = ordenada;

    return lista;
}

void inserir_lista_linear(lista_linear_t* lista, int valor) {
    if (cheia_lista_linear(lista)) {
        return;
    }
    if (lista->ordenada) {
        inserir_ordenada(lista, valor);
    } else {
        inserir_nao_ordenada(lista, valor);
    }
}

void inserir_nao_ordenada(lista_linear_t* lista, int valor) {
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}

void inserir_ordenada(lista_linear_t* lista, int valor) {
    if (!cheia_lista_linear(lista)) {
        int i;
        for (i = lista->tamanho - 1; i >= 0; --i) {
            if (lista->elementos[i] < valor) {
                lista->elementos[i + 1] = valor;
                break;
            }
            lista->elementos[i + 1] = lista->elementos[i];
        }
        if (i < 0) {
            lista->elementos[0] = valor;
        }
        lista->tamanho++;
    }
}

int busca_linear(lista_linear_t *lista, int valor) {
    int indice = 0;
    while(indice < lista->tamanho) {
        if (lista->elementos[indice] == valor) {
            return indice;
        }
        indice++;
    }
    return -1;
}

int busca_binaria(struct lista_linear_t* lista, int valor) {
    int inicio = 0;
    int fim = lista->tamanho - 1;
    
    while(inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        
        if (lista->elementos[meio] == valor) {
            return meio;
        }
        
        if (lista->elementos[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int buscar_lista(lista_linear_t* lista, int valor) {
    if (lista->ordenada) {
        return busca_binaria(lista, valor);
    }
    return busca_linear(lista, valor);
}

bool cheia_lista_linear(lista_linear_t* lista) {
   return lista->tamanho == lista->capacidade;
}