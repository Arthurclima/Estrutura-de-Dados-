#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"


Item * criarItem(int Chave) {
    Item * I = (Item *) malloc (sizeof(Item));
    if (I == NULL) {
        printf ("ERRO: Nao foi possivel alocar memoria para o item.");
            return NULL;
    }

    I -> Chave = Chave;
    I -> Anterior = NULL;

}

Pilha * criarpilha(){
    Pilha * P = (Pilha *) malloc (sizeof(Item));
    if (P == NULL){
        printf ("ERRO: Nao foi possivel alocar memoria para o item.");
            return NULL;
    }

    P -> Tamanho = 0;
    P -> Topo = NULL;

    return I; 
}


void empilhar(Pilha * P, Item * I){

    I -> Anterior;
    P -> Topo = I;
    P -> Tamanho++;
}


void desempilhar(Pilha * P){

    if (P -> Tamanho == 0) {
        printf("ERRO: a pilha está vazia\n");
        return;
    }

    Item * I = P -> Topo;
    P -> Topo = I -> Anterior;
    free(I);
    P -> Tamanho--;

}


