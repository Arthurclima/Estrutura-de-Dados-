#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp; //fp é um ponteiro para arquivo
    fp = fopen("Lista.txt", "r"); 

    if (fp == NULL){
        printf("ERRO: arquivo nao foi aberto! \n");
        exit(1);
    }

    int Qtd;
    float Preco;
    char Item[50];

    for(int i = 0; i < 4; i++){
        fscanf(fp, "%s %d %f\n", Item, &Qtd, &Preco);
        printf("%s \t %d \t %.2f\n", Item, Qtd, Preco);
    }

    fclose(fp);
    return 0;
}