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

    while (fscanf(fp, "%d %f %s", &Qtd, &Preco, &Item) != EOF) {
            printf("%d \t %f \t %s", Qtd, Preco, Item  );
}


    fclose(fp);
    return 0;
}