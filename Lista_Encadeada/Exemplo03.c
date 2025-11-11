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

    printf("%X \t %d \n", A, A->chave);
    printf("%X \t %d \n", B, B->chave);
    printf("%X \t %d \n", C, C->chave);
    printf("%X \t %d \n", D, D->chave);
    
// Construindo o encadeamento (Lista) A, B, C, D

    A->Proximo = B;
    B->Proximo = C;
    C->Proximo = D;
    D->Proximo = NULL;


    printf("%d\n", A ->chave); //17
    printf("%d\n", A->Proximo->chave); //29
    printf("%d\n", B->Proximo->chave); //41
    printf("%d\n", B->Proximo->Proximo->chave); //97

//Inserir o item X, com chave 73, antes do A

    Item * X = (Item*) malloc(sizeof(Item));
    X->chave = 73;
    X->Proximo = NULL; // Desnecessário
    X->Proximo = A;


}
