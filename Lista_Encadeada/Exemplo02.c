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
    
// Construindo o encadeamento (Lista) A, C, B, D

    A->Proximo = C;
    B->Proximo = D;
    C->Proximo = B;
    D->Proximo = NULL;

    printf("%d\n", A ->chave); //17
    printf("%d\n", A->Proximo->chave); //41
    printf("%d\n", C->Proximo->Proximo->chave); //97

}
