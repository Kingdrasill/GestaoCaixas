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

void CadastrarClinte(char *nome, long long int, short int prioridade, int num_itens);
void AtenderCliente();
FilaPrioridade FecharCaixa();
void ImprimirFila();
void ImprimirStatus();

#endif