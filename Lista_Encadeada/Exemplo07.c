#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int chave;
    struct Item * Proximo;
    struct Item * Anterior;
    
} Item;


Item * CriarItem(int chave);
void ExibirLista(Item * Inicio); //Para lista não circular
void InserirItem(Item * Inicio, Item * I, int posicao);
void ExcluirItem(Item * Inicio, int posicao);

//Bloco Principal



int main(){
    
    Item * A = CriarItem (17);
    Item * B = CriarItem (29);
    Item * C = CriarItem (41);
    Item * D = CriarItem (97);
    Item * P = CriarItem (67);  //Inserir o item P, onde a chave é 67, logo após C.


    A->Proximo = B;
    B->Proximo = C;
    C->Proximo = P;
    P->Proximo = D;
    D->Proximo = NULL;
     
     Item * X = A; // X Aponta para o primeiro elemento

    A->Proximo = C; // Excluir elemento B
    free(B);
    ExibirLista (A);
    
    }

    Item * CriarItem(int chave){

        Item * X = (Item *) malloc (sizeof(Item));
        X->chave = chave;
        X->Proximo= NULL;
        return X;

    }

    void ExibirLista(Item * Inicio){
        Item * X = Inicio;

        for ( ; X != NULL; X = X->Proximo){
        printf("%d\t", X->chave);
        
    }
    }



