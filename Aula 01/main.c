#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Fracao.h"

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