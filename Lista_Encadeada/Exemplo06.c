#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int chave;
    struct Item * Proximo
} Item;

//Bloco Principal

int main(){
    
    Item * A = (Item*) malloc (sizeof(Item));
    Item * B = (Item*) malloc (sizeof(Item));
    Item * C = (Item*) malloc (sizeof(Item));
    Item * D = (Item*) malloc (sizeof(Item));

    A -> chave = 17;
    B -> chave = 29;
    C -> chave = 41;
    D -> chave = 97;

    A->Proximo = NULL;
    B->Proximo = NULL;
    C->Proximo = NULL;
    D->Proximo = NULL;

//Alguns testes

    //printf("%X \t %d \n", A, A->chave);
    //printf("%X \t %d \n", B, B->chave);
    //printf("%X \t %d \n", C, C->chave);
    //printf("%X \t %d \n", D, D->chave);
    
// Construindo o encadeamento (Lista) A, B, C, D

    A->Proximo = B;
    B->Proximo = C;
    C->Proximo = D;
    D->Proximo = A; //Encadeamento Circular


    //printf("%d\n", A ->chave); //17
    //printf("%d\n", A->Proximo->chave); //29
    //printf("%d\n", B->Proximo->chave); //41
    //printf("%d\n", B->Proximo->Proximo->chave); //97

//Percorrer a lista com estrutura de repetição (visitar todos os nós da lista)

     Item * X = A; // X Aponta para o primeiro elemento

    for (int i = 0; i < 15; i++, X = X->Proximo){
        printf("%X \t %d\n", X, X->chave);
        if (X == NULL) break;
    }
    }



