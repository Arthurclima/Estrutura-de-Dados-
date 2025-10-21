#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int chave;
    struct Item * Proximo
} Item;

//Bloco Principal

int main(){
    Item * I = (Item*) malloc (sizeof(Item));

    I->chave = 23;
    I->Proximo = NULL;

//Alguns testes

    printf("Endereço (hexadecimal): %X\n", I);
    printf("Chave: %d\n", I->chave);
    printf("%X\n", I->Proximo);
}