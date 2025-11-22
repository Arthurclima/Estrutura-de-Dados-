#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expressao.h"

// Função auxiliar para imprimir linha de separação
void printLine() {
    printf("----------------------------------------------------------------\n");
}

int main() {
    // Casos de teste baseados na tabela do PDF 
    const char *testes[] = {
        "7 6 1 * +",          // 1. Esperado: 35
        "7 2 * 4 +",          // 2. Esperado: 18
        "8 5 2 4 + * +",      // 3. Esperado: 38
        "6 2 / 3 + 4 *",      // 4. Esperado: 24
        "5 2 8 * 4 + * 9 +",  // 5. Esperado: 109 (Corrigido a ordem para pos-fixa correta do ex 5)
                              // Nota: O PDF mostra "5 2 8 * 4 + * +" mas o valor é 109 que vem de 9+(...)
                              // Assumi a string corrigida para gerar o resultado
        "2 3 + log 5 /",      // 6. Aprox 0.14
        "10 log 3 ^ 2 +",     // 7. Esperado: 3
        "45 60 + 30 cos *",   // 8. Aprox 90.93
        "0.5 45 sen 2 ^ +"    // 9. Esperado: 1
    };

    // Valores esperados aproximados para validação visual
    const char *infixaEsperada[] = {
        "(3+4)*5",
        "7*2+4",
        "8+5*(2+4)",
        "(6/2+3)*4",
        "9+5*(4+8*2) (Aprox)", // O teste 5 do PDF parece ter erro de digitação na posfixa vs infixa
        "log(2+3)/5",
        "log(10)^3+2",
        "(45+60)*cos(30)",
        "sen(45)^2+0.5" // ou 0.5+sen(45)^2
    };

    printf("=== AVALIADOR DE EXPRESSOES NUMERICAS - UCB ===\n\n");

    for (int i = 0; i < 9; i++) {
        char buffer[512];
        strcpy(buffer, testes[i]); // getFormaInFixa pode alterar a string com strtok

        printf("Teste %d:\n", i + 1);
        printf("Entrada Pos-Fixa: %s\n", testes[i]);
        
        // 1. Converter para Infixa
        char *infixa = getFormaInFixa(buffer);
        if (infixa) {
            printf("Gerado Infixa:    %s\n", infixa);
            printf("Ref Infixa PDF:   %s\n", infixaEsperada[i]);
            
            // Copia para a struct de teste (simulação do uso da struct)
            Expressao exp;
            strcpy(exp.posFixa, testes[i]);
            strcpy(exp.inFixa, infixa);
            
            // 2. Calcular Valor
            exp.Valor = getValorPosFixa(testes[i]);
            printf("Valor Calculado:  %.4f\n", exp.Valor);
            
            free(infixa); // Liberar memória alocada em getFormaInFixa
        } else {
            printf("Erro na conversao para Infixa.\n");
        }
        printLine();
    }

    return 0;
}