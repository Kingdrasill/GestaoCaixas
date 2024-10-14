#ifndef FILAPRIORIDADE_H
#define FILAPRIORIDADE_H

#include "cliente.h"

typedef struct Bloco Bloco;
typedef struct FilaPrioridade FilaPrioridade;

struct Bloco {
    Cliente cliente;
    Bloco *prox;
};

struct FilaPrioridade
{
    Bloco *first;
    Bloco *last;
    int qtd;
};

void VaziaFila(FilaPrioridade *f);
void InserirFila(FilaPrioridade *f, Cliente c);
void RemoverFila(FilaPrioridade *f);
void ImprimirFila(FilaPrioridade *f);


#endif