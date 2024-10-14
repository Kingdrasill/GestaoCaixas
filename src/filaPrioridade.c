#include "filaPrioridade.h"

void VaziaFila(FilaPrioridade *f)
{
    f->first = (Bloco*) malloc (sizeof(Bloco));
	f->last  = f->first;
	f->first->prox = NULL;
    f->qtd = 0;
}

void InserirFila(FilaPrioridade *f, Cliente c)
{
    if(f->first == f->last){
        f->last->prox = (Bloco*) malloc (sizeof(Bloco));
        f->last = f->last->prox;
        f->last->cliente = c;
        f->last->prox = NULL;
    }
    else {
        Bloco *tmp = (Bloco*) malloc (sizeof(Bloco));
        tmp->cliente = c;

        Bloco *aux = f->first;

        while(aux->prox != NULL && aux->prox->cliente.Prioridade <= c.Prioridade) {
            aux = aux->prox;
        }

        tmp->prox = aux->prox;
        aux->prox = tmp;

        if(tmp->prox == NULL) {
            f->last = tmp;
        }
    }
    f->qtd += 1;
}

void RemoverFila(FilaPrioridade *f)
{
    if(f->first == f->last){
        return;
    }
    Bloco *aux, *tmp;
    
    tmp = f->first;
    aux = tmp->prox;
    tmp->prox = aux->prox;
    free(aux);
    f->qtd -= 1;
}

void ImprimirFila(FilaPrioridade *f)
{
    Bloco *aux = f->first->prox;

    printf("Nome - CPF - Prioridade - Itens: \n");
    while(aux != NULL) {
        ImprimirCliente(aux->cliente);
        aux = aux->prox;
    }
}
