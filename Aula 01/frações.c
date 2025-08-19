#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definição do TAD Função

typedef struct{
    int Numerador;
    int Denominador;
} Fracao;

int calcularMDC(int A, int B);
Fracao simplificarFracao(Fracao F) {
    int mdc = calcularMDC(F.Numerador, F.Denominador);
    F.Numerador = F.Numerador / mdc;
    F.Denominador = F.Denominador / mdc;
    return F;
}

Fracao subtrairfracoes(Fracao F, Fracao G){
    Fracao Resposta;
    Resposta.Denominador = F.Denominador * G.Denominador;
    Resposta.Numerador = (F.Numerador * G.Denominador) - (G.Numerador * F.Denominador);
    Resposta = simplificarFracao(Resposta);
    return Resposta;
}

Fracao somarfracoes(Fracao F, Fracao G){
    Fracao Resposta;
    Resposta.Denominador = F.Denominador * G.Denominador;
    Resposta.Numerador = (F.Numerador * G.Denominador) + (G.Numerador * F.Denominador);
    Resposta = simplificarFracao(Resposta);
    return Resposta;
}

Fracao criarFracao(int N, int D) {
    Fracao F;
    F.Numerador = N;
    F.Denominador = D;
    return F;
}

void exibirFracao(Fracao F){
    printf("%d/%d\t", F.Numerador, F.Denominador);
}

int calcularMDC(int A, int B){
    if (A < 0) A = -A;
    if (B < 0) B = -B;

    while(A % B != 0) {
        int temp = A;
        A = B;
        B = temp % B;
    }

    return(B);
}

int main(){
    system ("cls");

    Fracao F1 = criarFracao(24, 30);
    F1 = simplificarFracao (F1);
    
    Fracao F2 = criarFracao(-30, 40);
    F2 = simplificarFracao (F2);
    
    Fracao F3 = criarFracao(37, 42);
    F3 = simplificarFracao (F3);
    
    Fracao F4 = criarFracao(5, 6);
    Fracao F5 = criarFracao(4, 9);
    Fracao F6 = somarfracoes(F4, F5);
    Fracao F7 = subtrairfracoes(F4, F5);
    Fracao F8 = criarFracao (3, 4);
    Fracao F9 = criarFracao (7, 9);
    Fracao F10 = criarFracao (5, 12);
    Fracao F11 = subtrairfracoes (F8, F9);
    Fracao F12 = somarfracoes (F10, F11);
    exibirFracao(F1);
    exibirFracao(F2);
    exibirFracao(F3);
    exibirFracao(F6);
    exibirFracao(F7);
    exibirFracao(F12);
    
}

