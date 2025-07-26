//include guards
#ifndef MATRIZ_H
#define MATRIZ_H

// Criação da TMatriz

typedef struct {
    int linhas;
    int colunas;
    char **matriz; //matriz atual armazenada
} TMatriz;


TMatriz* matriz_criar(int linhas , int colunas);

int matriz_preencher(TMatriz* matriz , int linhas , int colunas);

void matriz_completa(TMatriz* matriz);

void matriz_apagar(TMatriz* matriz);

void clearScreen(); // Limpa a tela/console

#endif 
