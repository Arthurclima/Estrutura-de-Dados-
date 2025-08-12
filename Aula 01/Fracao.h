#ifndef Fracao_H
#define Fracao_H

typedef struct{
    int Numerador;
    int Denominador;
} Fracao;

void exibirfracao(Fracao F);
int calcularMDC(int A, int B);
Fracao simplificarFracao(Fracao F);
Fracao criarFracao(int F, int D);
Fracao somarFracoes(Fracao F, Fracao G);
Fracao subtrairFracoes(Fracao F, Fracao G);

#endif