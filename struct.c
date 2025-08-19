#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_NOME 150
#define Numero_pessoa 15
#define endereco_pessoa 200

typedef struct Ficha
    {
        char nome [TAM_NOME];
        char Numero [Numero_pessoa];
        char endereco [endereco_pessoa];

    } Ficha;

int main(int argc, char* argv[]){

    Ficha A;
    strcpy(A.nome, "Maria Alves");
    strcpy(A.Numero, "(61) 12345-6789");
    strcpy(A.endereco, "Shis 12 25 13");

    printf("%s\t %s\t %s", A.nome, A.endereco, A.Numero);
    

    return 0;
}
