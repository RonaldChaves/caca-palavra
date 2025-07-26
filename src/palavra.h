//include guards
#ifndef PALAVRA_H
#define PALAVRA_H

#include "coordenadas.h"
#include "ocorrencias.h"
#include "matriz.h"

// Criação do TPalavra

typedef struct {
    char palavra_bus[100]; // Armazena a palavra em si
    TCoordenadas pos_comeco; // Posicao inicial da palavra
    TCoordenadas pos_fim; // Posicao final da palavra
    int achou; // Verifica se achou a palavra (1 para sim, 0 para nao)
} TPalavra;

void palavra_criar(TPalavra* p, const char* str); 

void palavras_ler(TPalavra** palavras, int* qtd_palavras, TMatriz* matriz);

void palavra_procurar(TPalavra* palavra, TOcorrencias* ocorrencias, TMatriz* matriz);

int verifica_direcao(TPalavra* palavra, TMatriz* matriz, int i, int j, int dx, int dy);

void palavra_buscar_matriz(int qtd_palavras, TPalavra* palavras, TOcorrencias* ocorrencias, TMatriz* matriz);

void palavras_apagar(TPalavra* palavras);

#endif