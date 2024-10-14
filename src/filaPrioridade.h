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
};

void Vazia(FilaPrioridade *f);
void Inserir(FilaPrioridade *f, Cliente c);
void Remover(FilaPrioridade *f);
void Imprimir(FilaPrioridade *f);


#endif