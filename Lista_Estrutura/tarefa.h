#ifndef TAREFA_H
#define TAREFA_H

#define TAMANHO_TITULO 96
#define TAMANHO_NOME 48

// Outra maneira de fazer:

//typedef enum {A_FAZER, EM_ANDAMENTO, FEITO} Tipos_Status;

#define A_FAZER 0
#define EM_ANDAMENTO 1
#define FEITO 2

//Definindo a estrutura de um elemento da lista

typedef struct 
{
    char Titulo[TAMANHO_TITULO];
    char Responsavel [TAMANHO_NOME];
    int Status;
    float Progresso;
    int Avaliacao;

} Tarefa;

//Definindo a estrutura da lista de tarefas

typedef struct 
{
    Tarefa * Dados;
    int Capacidade;
    int Tamanho;

}Lista;

Lista * CriarLista(int C);
void DestruirLista(Lista * L);
void AdicionarTarefa(Lista*L, Tarefa T);
void GerarHTMLTabela(Lista *Lista, char *CaminhoArquivo);


#endif