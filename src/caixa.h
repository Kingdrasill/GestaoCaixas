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

Caixa CadastrarCaixa(int num_id);
void CaixaCadastrarCliente(Caixa *c, char *nome, long long int cpf, short int prioridade, int num_itens);
void AtenderCliente(Caixa *c);
void AbrirCaixa(Caixa *c);
FilaPrioridade FecharCaixa(Caixa *c);
void CaixaImprimirFila(Caixa *c);
void ImprimirEstado(Caixa *c);

#endif