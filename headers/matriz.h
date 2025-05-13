//include guards
#ifndef MATRIZ_H
#define MATRIZ_H

#include "coordenadas.h"
// Criação da TMatriz

typedef struct {
    char matriz; // Matriz atual (gerada)
    TCoordenadas dimensao; // Limites ou coordenadas da matriz ex: 4x4, 8x6
} TMatriz;

#endif 