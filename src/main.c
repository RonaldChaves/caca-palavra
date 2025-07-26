#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Usado p/ funcao Sleep()

// Declaração dos TAD's criados
#include "matriz.h"
#include "coordenadas.h"
#include "palavra.h"
#include "ocorrencias.h"

int main() {
    int c_i, c_j;

    printf("Insira as coordenadas da matriz: \n");
    scanf("%d %d", &c_i, &c_j);
    
    // Inicializa a matriz
    TMatriz* matriz = matriz_criar(c_i, c_j);
    
    clearScreen();
    printf("Insira os valores da matriz %dx%d (apenas letras minúsculas):\n", matriz->linhas, matriz->colunas);
    
    int matriz_preenchida = matriz_preencher(matriz, matriz->linhas, matriz->colunas);
    
    if (!matriz_preenchida) {
        printf("\nERROR: Matriz nula ou mal preenchida!\n");
        return 0;
    }
    matriz_completa(matriz);
    sleep(1);

    // Inicializa as ocorrencias
    TOcorrencias ocorrencias;
    ocorrencias_inicializar(&ocorrencias);
    ocorrencias_preencher(&ocorrencias, matriz);
     ocorrencias_printar(&ocorrencias);
    
    matriz_completa(matriz);
    
    // Inicializa as palavras
    /*TPalavra* palavras;
    int qtd_palavras;

    palavras_ler(&palavras, &qtd_palavras, matriz);
    palavra_buscar_matriz(qtd_palavras, palavras, &ocorrencias, matriz);*/

    // Libera memória
    //palavras_apagar(palavras);
    matriz_apagar(matriz);
   
    return 0;
}
