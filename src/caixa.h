#ifndef CAIXA_H
#define CAIXA_H

#include "filaPrioridade.h"
#include <stdbool.h>

typedef struct Caixa Caixa;

struct Caixa{
    int Num_Id;
    bool Estado;
    FilaPrioridade Fila;
};

#endif