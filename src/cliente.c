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

void Imprimir(Cliente c)
{
    printf("%s", c.Nome);
    printf("%lld", c.Cpf);
    printf("%d", c.Prioridade);
    printf("%d", c.Num_Itens);
}