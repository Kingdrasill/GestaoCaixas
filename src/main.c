#include "caixa.h"

int main()
{
   Caixa c = CadastrarCaixa(1); 

   AbrirCaixa(&c);

   CaixaCadastrarCliente(&c, "1", 1, 1, 1);
   CaixaCadastrarCliente(&c, "2", 2, 2, 2);
   CaixaCadastrarCliente(&c, "3", 3, 3, 3);
   CaixaCadastrarCliente(&c, "4", 4, 3, 4);
   CaixaCadastrarCliente(&c, "5", 5, 1, 5);
   CaixaCadastrarCliente(&c, "6", 6, 2, 6);
   CaixaCadastrarCliente(&c, "7", 7, 2, 7);
   CaixaCadastrarCliente(&c, "8", 8, 3, 8);
   CaixaCadastrarCliente(&c, "9", 9, 1, 9);

   ImprimirEstado(&c);

   return 0;
}
