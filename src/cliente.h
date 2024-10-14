#ifndef LISTA_H
#define LISTA_H

#define NAMESIZE 100

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Cliente Cliente;

struct Cliente
{
    char Nome[NAMESIZE + 1];
    long long int Cpf;
    short int Prioridade;
    int Num_Itens;
};

Cliente CadastrarCliente(char *nome, long long int cpf, short int prioridade, int num_itens);
void ImprimirCliente(Cliente c);

#endif