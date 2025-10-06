#include "libprg/libprg.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIM 1
#define NAO 2

pilha_t* criarPilha(pilha_t* pilha) {
    int capacidade;
    printf("criando pilha\n");
    printf("Você esta criando sua pilha!! Qual tamanho dela? ");
    scanf("%d", &capacidade);
    pilha_t* p = malloc (sizeof(pilha_t));
    p->elementos = malloc(capacidade * sizeof(int));
    p->topo = -1;
    p->capacidade = capacidade;
    printf("O tamanha da sua pilha é %d\n", capacidade);
    return p;
}

void pilha_cheia(pilha_t* pilha) {
    if (pilha->topo == pilha->capacidade - 1){
        printf("Sua pilha já está cheia :( \n");
        printf("Quer alocar mais espaço na memoria para colocar um novo elemento?\n");
        printf("Digite %d para SIM ou %d para NAO: ", SIM, NAO);
        int opcap;
        scanf("%d", &opcap);

        switch (opcap) {
            case SIM:
                printf("Certo, vamos alocar memoria!\n");
                pilha->capacidade *= 2;
                int* novo = realloc(pilha->elementos, pilha->capacidade * sizeof(int));
                //verificando se houve erro ao realocar memeoria
                if (novo == NULL) {
                    printf("Erro alocar memoria!");
                    exit(1);
                }
                pilha->elementos = novo;
                break;

            case NAO:
                printf("Você optou por não aumentar a pilha.\n");
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }
    }
}

int empilhar(pilha_t* pilha) {

    int valor;

    if (pilha->topo == pilha->capacidade - 1) {
        pilha_cheia(pilha);
    }

    printf("Digite o oque quer armazenar: ");
    scanf("%d", &valor);

    pilha->topo++;
    pilha -> elementos[pilha->topo] = valor;
    return 1;
}

int desempilha(pilha_t* pilha) {
    if (pilha->topo == -1) {
        printf("Pilha vazia, não é possível desempilhar.\n");
        return -1; // ou outro valor que faça sentido
    }
    int valor = pilha->elementos[pilha->topo];
    pilha->topo--;
    return valor;
}

int tamanho(pilha_t* pilha) {

    return pilha->topo + 1;
}

void destruir(pilha_t* pilha) {
    free(pilha->elementos);
    free(pilha);
}