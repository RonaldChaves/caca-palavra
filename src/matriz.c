#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "coordenadas.h"
#include "matriz.h"
#include "palavra.h" 
#include "ocorrencias.h"


TMatriz* matriz_criar(int linhas , int colunas){
    TMatriz* matriz_criada = (TMatriz*) malloc(sizeof(TMatriz));
    if (matriz_criada == NULL) return NULL; // retorna 'falha'
    
    matriz_criada->linhas = linhas;
    matriz_criada->colunas = colunas;
    matriz_criada->matriz = NULL;
    
    return matriz_criada;
}

int matriz_preencher(TMatriz* matriz_criada, int linhas, int colunas) {

    matriz_criada->matriz = (char**) malloc(linhas * sizeof(char*));
    if (matriz_criada->matriz == NULL) return 0; // retorna 'falha'

    for (int i = 0; i < linhas; i++) {
        matriz_criada->matriz[i] = (char*) malloc((colunas + 1) * sizeof(char)); // +1 para '\0'

        if (matriz_criada->matriz[i] == NULL) return 0; // retorna 'falha'

        scanf("%s", matriz_criada->matriz[i]);

        if (strlen(matriz_criada->matriz[i]) != colunas) {
            printf("Linha %d inválida: esperava %d letras.\n", i + 1, colunas);
            return 0; // retorna 'falha'
        }
        
        // Verifica de se a entrada foram apenas minusculos (letras)
        char* teste = matriz_criada->matriz[i];

        for (int j = 0; j < colunas; j++) {
            char c = teste[j];

            if (c < 'a' || c > 'z'){ // Verifica se na string tem valores 'apenas' entre a e z 
                return 0; // retorna 'falha'
            }
        }
    
    }

    return 1; // retorna 'sucesso'
}

void matriz_completa(TMatriz* matriz){
    
    printf("\nMatriz atual: \n");
    printf("\n");
    for(int i = 0; i < matriz->linhas; i++){
        for(int j = 0; j < matriz->colunas; j++){
            printf("%c ", matriz->matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void matriz_apagar(TMatriz* matriz){
    free(matriz);
}

void clearScreen(){
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux/Unix/MacOS
    #endif
}
