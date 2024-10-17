#ifndef MENU_H
#define MENU_H

#define NUM_CAIXAS 5

#include "caixa.h"

#include <time.h>

void Menu();
void OptionCadastrarCliente(Caixa *caixas);
void OptionAtenderCliente(Caixa *caixas);
void OptionAbrirFecharCaixa(Caixa *caixas);
void OptionImprimirFilas(Caixa *caixas);
void OptionImprimirStatusCaixas(Caixa *caixas);

void ClearScreen();
void Message();

#endif