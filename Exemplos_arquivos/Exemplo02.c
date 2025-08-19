#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp; //fp é um ponteiro para arquivo
    fp = fopen("c:/Temp/teste.txt", "w"); //abre teste.txt para escrita

    if (fp == NULL){
        printf("ERRO: arquivo nao foi aberto! \n");
        exit(1);
    }

    printf("Arquivo aberto/criado!\n");

    fclose(fp);
    return 0;
}