#include "menu.h"

void Menu()
{
    srand(time(NULL));
    Caixa caixas[NUM_CAIXAS];

    for (size_t i = 0; i < NUM_CAIXAS; i++) { 
        caixas[i] = CadastrarCaixa(i+1);
        AbrirCaixa(&caixas[i]); 
    }
    
    int opcao = 1;

    while (opcao != 0) {
        ClearScreen();

        printf("\tSistema de Gestão de Filas em Supermecado\n");
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

                printf("Obrigrado por usar o Sistema!\n");
                
                Message();
                break;
            case 1:
                ClearScreen();

                OptionCadastrarCliente(caixas);
                
                Message();
                break;
            case 2:
                ClearScreen();

                OptionAtenderCliente(caixas);
                
                Message();
                break;
            case 3:
                ClearScreen();

                OptionAbrirFecharCaixa(caixas);
                
                Message();
                break;
            case 4:
                ClearScreen();

                OptionImprimirFilas(caixas);
                
                Message();
                break;
            case 5:
                ClearScreen();

                OptionImprimirStatusCaixas(caixas);
                
                Message();
                break;
            default:
                ClearScreen();
                
                printf("Opção Inválida!\n");

                Message();
                break;
        }
    }
}

void OptionCadastrarCliente(Caixa *caixas)
{
    int c = 0;
    printf("Qual caixa deseja cadastrar um cliente dentre os %d caixas: ", NUM_CAIXAS);
    scanf("%d", &c);
    getchar();

    if(c > 0 && c <= NUM_CAIXAS) {
        if (caixas[c-1].Estado) {
            char nome[NAMESIZE + 1];
            printf("\nNome do cliente: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';

            long long int cpf;
            while(true) {
                printf("CPF do cliente (11 digitos): ");
                scanf("%lld", &cpf);
                if (cpf < 10000000000 && cpf > 99999999999) {
                    printf("\nCPF Imválido! Deve conter 11 digitos!\n");
                }
                else {
                    break;;
                }
            }

            short int prioridade;
            while(true) {
                printf("Prioridade do cliente (1 - %d): ", MIN_PRIO);
                scanf("%hd", &prioridade);
                if (prioridade < 1 && prioridade > MIN_PRIO) {
                    printf("\nPrioridade Imválida! Deve estar entre 1 - %d!\n", MIN_PRIO);
                }
                else {
                    break;
                }
            }

            int num_itens;
            printf("Número de itens no carrinho do cliente: ");
            scanf("%d", &num_itens);

            CaixaCadastrarCliente(&caixas[c-1], nome, cpf, prioridade, num_itens);

            printf("\nCliente cadastrado!\n");
        } else {
            printf("\nO caixa está fechado\n");
        }
    }
    else {
        printf("\nOpção de caixa inválida!\n");
    }
}


void OptionAtenderCliente(Caixa *caixas)
{
    int c = 0;
    printf("Qual caixa deseja atender um cliente dentre os %d caixas: ", NUM_CAIXAS);
    scanf("%d", &c);

    if(c > 0 && c <= NUM_CAIXAS) {
        AtenderCliente(&caixas[c-1]);
        printf("\nCliente atendido no caixa %d!\n", c);
    }
    else {
        printf("\nOpção de caixa inválida!\n");
    }
}

void OptionAbrirFecharCaixa(Caixa *caixas)
{
    int c = 0;
    int count = 0;
    printf("Qual caixa deseja abrir ou fechar dentre os %d caixas: ", NUM_CAIXAS);
    scanf("%d", &c);
    
    if(c > 0 && c <= NUM_CAIXAS) {
        int o = 0;
        printf("\nDeseja abrir ou fechar o caixa (1 - Abrir / 2 - Fechar): ");
        scanf("%d", &o);

        switch (o) {
            case 1:
                if (!caixas[c-1].Estado) {
                    AbrirCaixa(&caixas[c-1]);
                    printf("\nCaixa %d foi aberto!\n", c);
                }
                else {
                    printf("\nCaixa %d já está aberto!\n", c);
                }
                break;
            case 2:
                for (size_t i = 0; i < NUM_CAIXAS; i++) { 
                    if(!caixas[i].Estado) {
                        count += 1;
                    }
                }
                if (count < NUM_CAIXAS - 1) {
                    if (caixas[c-1].Estado) {
                        FilaPrioridade clientes = FecharCaixa(&caixas[c-1]);
                        
                        Bloco *aux = clientes.first->prox;
                        while(aux != NULL) {
                            bool cont = true;
                            int index = c-1;
                            while (cont) {
                                index = rand() % NUM_CAIXAS;
                                if (index == c-1 || !caixas[index].Estado) {
                                    cont = true;
                                } else {
                                    cont = false;
                                }
                            }
                            CaixaCadastrarCliente(&caixas[index], aux->cliente.Nome, aux->cliente.Cpf, aux->cliente.Prioridade, aux->cliente.Num_Itens);
                            aux = aux->prox;
                        }
                        printf("\nCaixa %d foi fechado!\n", c);
                    } else {
                        printf("\nCaixa %d já está fechado!\n", c);
                    }
                } else {
                    printf("\nCaixa não pode ser fechado, todos os outros caixas estão fechados!\n");
                }
                break;
            default:
                printf("\nOpção Inválida\n");
                break;
        }
    } else {
        printf("\nOpção de caixa inválida!\n");
    }
}

void OptionImprimirFilas(Caixa *caixas)
{
    printf("Clientes em Espera\n\n");
    for (size_t i = 0; i < NUM_CAIXAS; i++)
    {
        CaixaImprimirFila(&caixas[i]);
        printf("\n");
    }
}

void OptionImprimirStatusCaixas(Caixa *caixas)
{
    printf("Estados dos caixas\n\n");
    for (size_t i = 0; i < NUM_CAIXAS; i++)
    {
        ImprimirEstado(&caixas[i]);
        printf("\n");
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