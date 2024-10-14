#ifndef MENU_H
#define MENU_H

#define NUM_CAIXAS 5

#include "caixa.h"

void Menu();
void CadastrarCliente(Caixa *caixas);
void AtenderCliente(Caixa *caixas);
void AbrirFecharCaixa(Caixa *caixas);
void ImprimirFilas(Caixa *caixas);
void ImprimirStatusCaixas(Caixa *caixas);

#endif