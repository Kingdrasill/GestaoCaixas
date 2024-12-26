# Sistema de Gestão de Filas em Supermercado

O objetivo deste projeto é o desenvolvimento de um sistema de gestão de filas para caixas de um supermecado. Neste sistema as filas são ordenadas por prioridade, sendo elas 1, 2 e 3. O sistema foi desenvolvido na linguagem C utilizando filas com prioridades para organizar o atendimento dos clientes.

# Implementação

Foram criados os seguintes arquivos, que estão na pasta `src` para separa o código para ficar mais intuitivo:

- `cliente.h` e `cliente.c` - Tratam sobre os dados do cliente e a implementação de seus metódos.
- `filaPrioridade.h` e `filaPrioridade` - Tratam sobre a fila com prioridade e sua implementação.
- `caixa.h` e `caixa.c` - Tratam sobre os dados do caixa e implementação dos metódos.
- `menu.h` e `menu.c` - Tratam sobre a implementação dos metódos de um menu.
- `main.c` - Implementa o método main e chama o método que cria o menu.

## Cliente

Os dados de cada cliente do sistema foram armazendados em um *struct* chamado `Cliete` que possui os seguintes atributos:

- **Nome** - *array* de *chars* com tamanho máximo de 100 carateres que guarda o nome do clinte.
- **Cpf** - inteiro de 11 dígitos que aramzena o CPF do cliente.
- **Prioridade** - inteiro que representa a prioridade do cliete, pode ser 1 para alta prioridade, 2 para proridade média e 3 para prioridade média
- **Num_Itens** - inteiro que guarda a quantidade de itens no carrinho do cliente.

O cliente possui os seguintes métodos:

- **CadastrarCliente** - utilizado para cadastrar um cliente. Recebe os dados do cliente e retorna `Cliente`.
- **ImprimirCliente** - utilizado para imprimir os dados de um cliente, recebe um `Cliente`.

### CadastrarCliente

### ImprimirCliente

## Fila com Prioridade

A fila com prioridade é formada por dois *struct* que são utilziados para estruturar a mesma. O primeiro *struct* é o `Bloco` que onde os dados da fila são armazenados, ele possui os seguintes atributos:

- **cliente** - um *struct* de Cliente onde é armazenado o cliente na fila.
- **prox** - um ponteiro para o próximo `Bloco` da fila.

O segundo *struct* é o `FilaPrioridade` que aramzena os dados gerais da fila, ele possui os seguintes atributos:

- **first** - um ponteiro para o primeiro `Bloco` da fila.
- **last** - um ponteiro para o último `Bloco` da fila.
- **qtd** - inteiro que guarda a quantidade de elementos na fila.

A fila com prioridade possui os seguintes métodos:

- **EsvaziarFila** - utilizado para esvaziar uma fila, recebe a fila.
- **InserirFila** - utilizado para inserir um elemento na fila, recebe a fila e o cliente.
- **RemoverFila** - utilizado para remover o primeiro elemento de uma fila, recebe a fila.
- **ImprimirFila** - utilizado para imprimir os dados de uma fila, recebe a fila.

### EsvaziarFila

### InserirFila

### RemoverFila

### ImprimirFila

## Caixa

Os dados de um caixa do sistema são armazenados em um *struct* chamado **Caixa** que guarda os seguintes atributos:

- **Num_Id** - inteiro que guarda o número identificador do caixa.
- **Estado** - booleana que gurada se o caixa está aberto (**true**) ou feichado (**false**).
- **Fila** - `FilaPrioridade` que guarda a fila com prioridade de clientes do caixa.

O caixa possui os seguintes métodos:

- **CadastrarCaixa** - cadastra um caixa fechado e vazio no sistema, recebe o identificador e retorna `Caixa`.
- **CaixaCadastrarCliente** - cadastra um cliente na fila do caixa, recebe o caixa e os dados do cliente.
- **AtenderCliente** - atende e remove o primeiro cliente de sua fila, recebe o caixa.
- **AbrirCaixa** - abre um caixa do sistema, recebe o caixa.
- **FecharCaixa** - fecha um caixa do sistema retornando sua fila, recebe o caixa e retorna uma cópia da fila do caixa.
- **CaixaImprimirFila** - imprime a fila do caixa, recebe o caixa.
- **ImprimirEstado** - imprime o estado do caixa, recebe o caixa.

### CadastrarCaixa

### CaixaCadastrarCliente

### AtenderCliente

### AbrirCaixa

### FecharCaixa

### CaixaImprimirFila

### ImprimirEstado

## Menu

O menu do sistema é gerado pelo método `Menu` que dá ao usuário do sistema as seguintes opções de operações:

1. **Cadastrar um Cliente** - Opção para cadastrar um cliente em um caixa do sistema, feita pelo método `OptionCadastrarCliente`.
2. **Atender um Cliente** - Opção para atender o cliente de um caixa, feita pelo método `OptionAtenderCliente`.
3. **Abrir ou Fechar um Caixa** - Opção para abrir ou fechar um dos caixas do sistema, feita pelo método `OptionAbrirFecharCaixa`.
4. **Imprimir a Lista de Clientes em Espera** - Opção para imprimir os clientes em espera de cada caixa do sistema, feita pelo método `OptionImprimirFilas`.
5. **Imprimir o Status dos Caixas** - Opção para imprimir o estado e o número de clientes de cada caixa do sistema, feita pelo método `OptionImprimirStatusCaixas`.

Além destes métodos foram criados dois métodos auxiliares:

- **ClearScreen** - limpa o terminal de execução antes de mostrar o menu ou antes de executar uma ação do sistema.
- **Message** - mensagem que aparece após a execução de qualquer ação do sistema.

### OptionCadastrarCliente

### OptionAtenderCliente

### OptionAbrirFecharCaixa

### OptionImprimirFilas

### OptionImprimirStatusCaixas

# Compilação e Execução

O progama disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build             |
|  `make all`            | Executa os dois comandos anteriores de uma vez                                          |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                   |