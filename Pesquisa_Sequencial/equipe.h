#ifndef EQUIPE_H
#define EQUIPE_H

typedef struct 
{
    int Pos; //Posição final da equipe no Cb2024
    char Estado[30];
    char Equipe[50]; //Nome do time
    int Pts;
    int J;
    int V;
    int E;
    int D;
    int GP; // Gols pró
    int GC; // Gols contra
    int SG; // Saldo de Gols = GP - GC
    float Aproveitamento;
} Time;

Time * LerDados(char * Arquivo);

#endif
