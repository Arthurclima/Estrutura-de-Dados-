#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp; //fp é um ponteiro para arquivo
    fp = fopen("teste.txt", "a"); //abre teste.txt para escrita

    if (fp == NULL){
        printf("ERRO: arquivo nao foi aberto! \n");
        exit(1);
    }

    fprintf(fp, "Tabuada do 9:\n\n");

    printf("Arquivo aberto/criado!\n");

    int i;

    for(i = 1; i <= 10; i++){
        fprintf(fp, "9 x %d = %d\n", i, 9*i);
    }

    fprintf(fp, "\n");

    fclose(fp);
    return 0;
}