//include guards
#ifndef OCORRENCIAS_H
#define OCORRENCIAS_H

#include "coordenadas.h"
#include "matriz.h"

// Criação do TOcorrencias

typedef struct {
    int qtd; // Quantidade de ocoorencia da letra
    TCoordenadas* coords; // Posição desta ocorrencia
} TOcorrenciasLetra;

typedef struct {
    TOcorrenciasLetra letras[26];  // De 'a' até 'z', índice = letra - 'a'
} TOcorrencias;


void ocorrencias_inicializar(TOcorrencias* ocorrencias);

void ocorrencias_preencher(TOcorrencias* ocorrencias, TMatriz* matriz);

void ocorrencias_printar(TOcorrencias* ocorrencias);
#endif