//include guards
#ifndef PALAVRA_H
#define PALAVRA_H

#include <stdbool.h>  // Permite  o uso de boolean

#include "coordenadas.h"

// Criação do TPalavra

typedef struct {
    char palavra_bus; // Armazena a palavra em si
    TCoordenadas pos_comeco; // Posicao inicial da palavra
    TCoordenadas pos_fim; // Posicao final da palavra
    bool achou; // Verifica se achou a palavra (1 para sim, 0 para nao)
} TPalavra;

#endif