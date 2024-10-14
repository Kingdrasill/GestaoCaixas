#ifndef LISTA_H
#define LISTA_H

#define NAMESIZE 100
#define MINPRIO 3
#define MAXPRIO 1

#include <stdlib.h>
#include <stdio.h>

typedef struct Cliente Cliente;

struct Cliente
{
    char Nome[NAMESIZE + 1];
    long long int Cpf;
    short int Prioridade;
    int Num_Itens;
};

#endif