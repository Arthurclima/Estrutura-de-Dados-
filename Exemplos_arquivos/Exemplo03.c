#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp; //fp é um ponteiro para arquivo
    fp = fopen("teste.txt", "a"); //abre teste.txt para escrita

    if (fp == NULL){
        printf("ERRO: arquivo nao foi aberto! \n");
        exit(1);
    }

    fprintf(fp, "O Santos perdeu de 6 x 0!\n");

    printf("Arquivo aberto/criado!\n");

    fclose(fp);
    return 0;
}