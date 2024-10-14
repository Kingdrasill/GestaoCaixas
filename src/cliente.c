#include "cliente.h"

Cliente CadastrarCliente(char *nome, long long int cpf, short int prioridade, int num_itens)
{
    Cliente novo;
    strcpy(novo.Nome, nome);
    novo.Cpf = cpf;
    novo.Prioridade = prioridade;
    novo.Num_Itens = num_itens;
    return novo;
}

void ImprimirCliente(Cliente c)
{
    printf("%s - %lld - %d - %d\n", c.Nome, c.Cpf, c.Prioridade, c.Num_Itens);
}