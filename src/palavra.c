#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "coordenadas.h"
#include "matriz.h"
#include "palavra.h"
#include "ocorrencias.h"

#define TAM_MAX 100

void palavra_criar(TPalavra* p, const char* str) {
    strcpy(p->palavra_bus, str);

    // Inicializa coordenadas de início e fim como inválidas
    p->pos_comeco.linhas = -1;
    p->pos_comeco.colunas = -1;

    p->pos_fim.linhas = -1;
    p->pos_fim.colunas = -1;
}


void palavras_ler(TPalavra** palavras, int* qtd_palavras,TMatriz* matriz) {
    printf("Insira quantas palavras quer pesquisar (0 - 100):\n");
    scanf("%d", qtd_palavras);

    clearScreen();
    matriz_completa(matriz);
    
    *palavras = (TPalavra*) malloc((*qtd_palavras) * sizeof(TPalavra));
    if (*palavras == NULL) {
        printf("Erro ao alocar memória para as palavras!\n");
        exit(1);
    }

    for (int i = 0; i < *qtd_palavras; i++) {
        char buffer[TAM_MAX + 1];
        printf("Insira a %dª palavra: ", i + 1);
        scanf("%s", buffer);

        palavra_criar(&((*palavras)[i]), buffer);
    }
}


int verifica_direcao(TPalavra* palavra, TMatriz* matriz, int i, int j, int dx, int dy) {
    int len = strlen(palavra->palavra_bus);

    for (int k = 0; k < len; k++) {
        int ni = i + k * dx;
        int nj = j + k * dy;

        // Se sair da matriz
        if (ni < 0 || ni >= matriz->linhas || nj < 0 || nj >= matriz->colunas)
            return 0;

        // Se não bater a letra
        if (matriz->matriz[ni][nj] != palavra->palavra_bus[k])
            return 0;
    }

    return 1; // Achou!
}

void palavra_procurar(TPalavra* palavra, TOcorrencias* ocorrencias, TMatriz* matriz) {
    char primeira_letra = palavra->palavra_bus[0];
    int idx = primeira_letra - 'a';

    palavra->achou = 0;

    for (int k = 0; k < ocorrencias->letras[idx].qtd; k++) {
        int i = ocorrencias->letras[idx].coords[k].linhas;
        int j = ocorrencias->letras[idx].coords[k].colunas;

        // Testa todas as 8 direções: (-1,0), (1,0), (0,-1), (0,1), etc
        int direcoes[8][2] = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
        };

        for (int d = 0; d < 8; d++) {
            int dx = direcoes[d][0];
            int dy = direcoes[d][1];

            if (verifica_direcao(palavra, matriz, i, j, dx, dy)) {
                palavra->pos_comeco.linhas = i;
                palavra->pos_comeco.colunas = j;

                int len = strlen(palavra->palavra_bus);
                palavra->pos_fim.linhas = i + (len - 1) * dx;
                palavra->pos_fim.colunas = j + (len - 1) * dy;

                palavra->achou = 1;
                return; // Achou, não precisa procurar mais
            }
        }
    }

    // Se não achou em nenhuma direção
    palavra->pos_comeco.linhas = 0;
    palavra->pos_comeco.colunas = 0;
    palavra->pos_fim.linhas = 0;
    palavra->pos_fim.colunas = 0;
}

void palavra_buscar_matriz(int qtd_palavras, TPalavra* palavras, TOcorrencias* ocorrencias, TMatriz* matriz) {
    for (int i = 0; i < qtd_palavras; i++) {
        palavra_procurar(&palavras[i], ocorrencias, matriz);
    }

    clearScreen();
    matriz_completa(matriz);
    
    printf("Resultado: \n");
    for (int i = 0; i < qtd_palavras; i++) {
        printf("%d %d %d %d %s\n", 
            palavras[i].pos_comeco.linhas, palavras[i].pos_comeco.colunas,
            palavras[i].pos_fim.linhas, palavras[i].pos_fim.colunas,
            palavras[i].palavra_bus
        );
    }
}

void palavras_apagar(TPalavra* palavras){
    free(palavras);
}
