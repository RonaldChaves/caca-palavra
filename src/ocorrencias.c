#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "coordenadas.h"
#include "matriz.h"
#include "palavra.h" 
#include "ocorrencias.h"

void ocorrencias_inicializar(TOcorrencias* ocorrencias) {
    for (int i = 0; i < 26; i++) {
        ocorrencias->letras[i].qtd = 0;
        ocorrencias->letras[i].coords = NULL; // Inicializa vazio
    }
}

void ocorrencias_preencher(TOcorrencias* ocorrencias, TMatriz* matriz) {
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            char letra = matriz->matriz[i][j];
            int indice = letra - 'a';  // De 0 a 25

            if (indice < 0 || indice >= 26) continue;  // ignora não-letras

            int qtd_atual = ocorrencias->letras[indice].qtd;

            // Realoca espaço para mais uma coordenada
            ocorrencias->letras[indice].coords = (TCoordenadas*) realloc(
                ocorrencias->letras[indice].coords,
                (qtd_atual + 1) * sizeof(TCoordenadas)
            );

            // Armazena coordenada
            ocorrencias->letras[indice].coords[qtd_atual].linhas = i;
            ocorrencias->letras[indice].coords[qtd_atual].colunas = j;

            ocorrencias->letras[indice].qtd++;
        }
    }
}

// Caso queira visualizar a matriz (eu não usei no main.c)
void ocorrencias_printar(TOcorrencias* ocorrencias) {
    for (int i = 0; i < 26; i++) {
        if (ocorrencias->letras[i].qtd > 0) {
            printf("Letra '%c': %d ocorrências\n", 'a' + i, ocorrencias->letras[i].qtd);
            for (int j = 0; j < ocorrencias->letras[i].qtd; j++) {
                printf("  -> (%d, %d)\n",
                       ocorrencias->letras[i].coords[j].linhas,
                       ocorrencias->letras[i].coords[j].colunas);
            }
        }
    }
}