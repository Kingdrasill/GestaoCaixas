#include "filaPrioridade.h"

void Vazia(FilaPrioridade *f)
{
    f->first = (Bloco*) malloc (sizeof(Bloco));
	f->last  = f->first;
	f->first->prox = NULL;
}

void Inserir(FilaPrioridade *f, Cliente c)
{
    f->last->prox = (Bloco*) malloc (sizeof(Bloco));
    f->last = f->last->prox;
    f->last->cliente = c;
    f->last->prox = NULL;
}

void Remover(FilaPrioridade *f)
{
    if(f->first == f->last || f == NULL){
        return;
    }
    Bloco *aux, *tmp;
    
    tmp = f->first;
    aux = tmp->prox;
    tmp->prox = aux->prox;
    free(aux);
}

void Imprimir(FilaPrioridade *f)
{
    Bloco *aux;

    aux = f->first->prox;
    while(aux != NULL) {
        aux = aux->prox;
    }
}
