#include "menu.h"

void Menu()
{
    Caixa caixas[5] = {CadastrarCaixa(1), CadastrarCaixa(2), CadastrarCaixa(3), CadastrarCaixa(4), CadastrarCaixa(5)};

    for (size_t i = 0; i < 5; i++) { AbrirCaixa(&caixas[i]); }
    
    int opcao = 1;

    while (opcao != 0) {
        ClearScreen();

        printf("\n\tSistema de Gestão de Filas em Supermecado\n");
        printf("\n1 - Cadastrar um Cliente");
        printf("\n2 - Atender um Cliente");
        printf("\n3 - Abrir ou Fechar um Caixa");
        printf("\n4 - Imprimir a Lista de Clientes em Espera");
        printf("\n5 - Imprimir o Status dos Caixas");
        printf("\n0 -  Sair\n");
        printf("\nEscolha uma Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                ClearScreen();

                printf("\nObrigrado por usar o Sistema!\n");
                
                Message();
                break;
            
            default:
                ClearScreen();
                
                printf("\nOpção Inválida!\n");

                Message();
                break;
        }
    }
}

void ClearScreen() 
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Message()
{
    printf("\nAperte enter para continuar...");
    getchar();
    getchar();
}