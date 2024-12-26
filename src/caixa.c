#include "caixa.h"

Caixa CadastrarCaixa(int num_id)
{
    Caixa novo;
    novo.Num_Id = num_id;
    novo.Estado = false;
    EsvaziarFila(&novo.Fila);
    return novo;
}

void CaixaCadastrarCliente(Caixa *c, char *nome, long long int cpf, short int prioridade, int num_itens)
{
    Cliente novo = CadastrarCliente(nome, cpf, prioridade, num_itens);
    InserirFila(&c->Fila, novo);
}


void AtenderCliente(Caixa *c)
{
    RemoverFila(&c->Fila);
}

void AbrirCaixa(Caixa *c)
{
    c->Estado = true;
    EsvaziarFila(&c->Fila);
}

FilaPrioridade FecharCaixa(Caixa *c)
{
    FilaPrioridade copia = c->Fila;
    c->Estado = false;
    EsvaziarFila(&c->Fila);
    return copia;
}

void CaixaImprimirFila(Caixa *c)
{
    printf("Caixa %d\n", c->Num_Id);
    ImprimirFila(&c->Fila);
}

void ImprimirEstado(Caixa *c)
{
    printf("Caixa %d: ", c->Num_Id);
    if (c->Estado) {
        printf("Aberto - ");
    }
    else {
        printf("Fechado - ");
    }
    printf("%d\n", c->Fila.qtd);
}