#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "expressao.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


// Pilha para avaliação numérica 
typedef struct NodeFloat {
    float val;
    struct NodeFloat *prox;
} NodeFloat;

// Pilha para conversão de string (armazena texto e precedência)
typedef struct NodeStr {
    char *texto;
    int precedencia; // 1: +-, 2: */%, 3: ^, 4: func, 5: operandos
    struct NodeStr *prox;
} NodeStr;

// Funções de limpeza
static void freeNodeStrStack(NodeStr *topo) {
    while (topo) {
        NodeStr *t = topo;
        topo = topo->prox;
        if (t->texto) free(t->texto);
        free(t);
    }
}

static void freeNodeFloatStack(NodeFloat *topo) {
    while (topo) {
        NodeFloat *t = topo;
        topo = topo->prox;
        free(t);
    }
}

// Funções auxiliares para pilha de floats

void pushFloat(NodeFloat **topo, float v) {
    NodeFloat *novo = (NodeFloat*)malloc(sizeof(NodeFloat));
    if(novo) {
        novo->val = v;
        novo->prox = *topo;
        *topo = novo;
    }
}

float popFloat(NodeFloat **topo) {
    if (*topo == NULL) return 0.0;
    NodeFloat *temp = *topo;
    float v = temp->val;
    *topo = temp->prox;
    free(temp);
    return v;
}

// Funções auxiliares para pilha de strings

void pushStr(NodeStr **topo, char *txt, int prec) {
    NodeStr *novo = (NodeStr*)malloc(sizeof(NodeStr));
    if(novo) {
        novo->texto = strdup(txt); // Aloca cópia da string
        novo->precedencia = prec;
        novo->prox = *topo;
        *topo = novo;
    }
}

// Retorna o nó completo para podermos acessar texto e precedência
NodeStr* popStr(NodeStr **topo) {
    if (*topo == NULL) return NULL;
    NodeStr *temp = *topo;
    *topo = temp->prox;
    return temp; // Quem chama deve dar free no temp e no temp->text
}

// funções de utilidade

// Verifica se token é operador binário
int ehOpBinario(char *token) {
    return (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || 
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0 || 
            strcmp(token, "%") == 0 || strcmp(token, "^") == 0);
}

// Retorna prioridade para lógica de parênteses
int getPrecedencia(char *op) {
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return 1;
    if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0 || strcmp(op, "%") == 0) return 2;
    if (strcmp(op, "^") == 0) return 3;
    // Funções e operandos puros têm prioridade maior
    return 0; 
}

// Implementação das funções do "expressao.h"

float getValorPosFixa(const char *StrPosFixa) {
    NodeFloat *pilha = NULL;
    char *copia = strdup(StrPosFixa); // Cópia para usar strtok sem alterar original
    char *token = strtok(copia, " ");

    while (token != NULL) {
        // Verifica se é número (considerando sinal negativo no início ou dígitos)
        if (isdigit((unsigned char)token[0]) || (token[0] == '-' && isdigit((unsigned char)token[1]))) {
            pushFloat(&pilha, atof(token));
        } else if (ehOpBinario(token)) {
            // precisa de dois operandos
            if (pilha == NULL || pilha->prox == NULL) {
                free(copia);
                freeNodeFloatStack(pilha);
                return 0.0f; 
            }
            float b = popFloat(&pilha);
            float a = popFloat(&pilha);
            float res = 0;

            if (strcmp(token, "+") == 0) res = a + b;
            else if (strcmp(token, "-") == 0) res = a - b;
            else if (strcmp(token, "*") == 0) res = a * b;
            else if (strcmp(token, "/") == 0) res = a / b; // Assumindo não divisão por 0
            else if (strcmp(token, "%") == 0) res = fmod(a, b);
            else if (strcmp(token, "^") == 0) res = pow(a, b);

            pushFloat(&pilha, res);
        } else {
            // Funções unárias ou especiais
            // "raiz", "sen", "cos", "tg", "log"
            if (pilha == NULL) {
                free(copia);
                freeNodeFloatStack(pilha);
                return 0.0f; 
            }
            float a = popFloat(&pilha);
            float res = 0;

            if (strcmp(token, "raiz") == 0) res = sqrt(a);
            else if (strcmp(token, "log") == 0) res = log10(a); // Log decimal 
            else {
                // Trigonometria: Entrada em graus, converter para radianos 
                float rad = a * (M_PI / 180.0);
                if (strcmp(token, "sen") == 0) res = sin(rad);
                else if (strcmp(token, "cos") == 0) res = cos(rad);
                else if (strcmp(token, "tg") == 0) res = tan(rad);
            }
            pushFloat(&pilha, res);
        }
        token = strtok(NULL, " ");
    }

    if (pilha == NULL) {
        free(copia);
        return 0.0f; 
    }

    float resultadoFinal = popFloat(&pilha);
    // limpa qualquer coisa restante na pilha
    freeNodeFloatStack(pilha);
    free(copia);
    return resultadoFinal;
}

char * getFormaInFixa(const char *Str) {
    NodeStr *pilha = NULL;
    char *copia = strdup(Str);
    char *token = strtok(copia, " ");
    
    if (!token) { free(copia); return NULL; } // Erro ou string vazia

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // É operando: precedência máxima (5), não precisa de parênteses em volta dele mesmo
            pushStr(&pilha, token, 5);
        } 
        else if (ehOpBinario(token)) {
            NodeStr *b = popStr(&pilha);
            NodeStr *a = popStr(&pilha);
            
            if (!a || !b) { // Erro de consistência
                // liberar o que já foi retirado e a pilha restante
                if (b) { free(b->texto); free(b); }
                if (a) { free(a->texto); free(a); }
                freeNodeStrStack(pilha);
                free(copia);
                return NULL; 
            }

            int atualPrec = getPrecedencia(token);
            char buffer[512];
            char partA[256], partB[256];

            // Lógica de parênteses 
            // Se precedência do filho for menor que a do pai, usa parênteses
            if (a->precedencia < atualPrec) sprintf(partA, "(%s)", a->texto);
            else strcpy(partA, a->texto);
            
            int precisaParensB = (b->precedencia < atualPrec);
            if ((strcmp(token, "/") == 0 || strcmp(token, "-") == 0 || strcmp(token, "^") == 0) 
                 && b->precedencia == atualPrec) {
                precisaParensB = 1;
            }

            if (precisaParensB) sprintf(partB, "(%s)", b->texto);
            else strcpy(partB, b->texto);

            // Monta string sem espaços 
            sprintf(buffer, "%s%s%s", partA, token, partB);
            
            // Push resultado com a nova precedência
            pushStr(&pilha, buffer, atualPrec);

            // Limpeza
            free(a->texto); free(a);
            free(b->texto); free(b);
        }
        else {
            // Funções unárias (sen, cos, log...)
            NodeStr *a = popStr(&pilha);
            if (!a) { freeNodeStrStack(pilha); free(copia); return NULL; }

            char buffer[512];
            // Funções sempre envolvem o argumento em parênteses: sen(45)
            sprintf(buffer, "%s(%s)", token, a->texto);
            
            // Funções têm precedência alta (4), agem como bloco
            pushStr(&pilha, buffer, 4);

            free(a->texto); free(a);
        }
        token = strtok(NULL, " ");
    }
    NodeStr *resultado = popStr(&pilha);
    free(copia);

    if (!resultado) {
        freeNodeStrStack(pilha);
        return NULL;
    }
    if (pilha != NULL) { 
        // Sobrou coisa na pilha? free tudo e retorna NULL (erro)
        free(resultado->texto);
        free(resultado);
        freeNodeStrStack(pilha);
        return NULL; 
    }

    // Retorna a string alocada; chamador deve liberar o retorno
    char *ret = resultado->texto;
    free(resultado);
    return ret; 
}