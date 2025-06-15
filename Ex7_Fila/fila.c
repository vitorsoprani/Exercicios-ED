#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "fila.h"
typedef struct celula Celula;

struct celula{
    Amostra* amostra;
    Celula* prox;
};

struct fila{
    Celula* prim;
    Celula* ult;
};

Fila* fila_Cria() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    assert(f);

    f->prim = NULL;
    f->ult = NULL;

    return f;
}

void* fila_Destroi(Fila* f) {
    if (f == NULL)
        return NULL;
    
    Celula* ant = NULL;
    Celula* atual = f->prim;

    while (atual != NULL) {
        liberaAmostra(atual->amostra);
        
        ant = atual;
        atual = atual->prox;

        free(ant);
    }

    free(f);

    return NULL;
}

void fila_Insere(Fila* f, Amostra* a) {
    assert(f);
    assert(a);
    
    Celula* c = (Celula*)malloc(sizeof(Celula));
    assert(c);
    c->amostra = a;
    c->prox = NULL;

    if (f->ult != NULL)
        f->ult->prox = c;
    else
        f->prim = c;

    f->ult = c;
}

void fila_InserePrioritario(Fila* f, Amostra* a) {
    assert(f);
    assert(a);

    Celula* c = (Celula*)malloc(sizeof(Celula));
    assert(c);
    c->amostra = a;

    c->prox = f->prim;
    if (f->ult == NULL)
        f->ult = c;
    f->prim = c;
}

Amostra* fila_Remove(Fila* f) {
    assert(f);
    Celula* c;
    Amostra* a;

    // Fila vazia
    if (f->prim == NULL)
        return NULL;
    
    c = f->prim;
    a = c->amostra;
    
    // Unico elemento na fila
    if (f->prim == f->ult)
        f->prim = f->ult = NULL;
    else
        f->prim = f->prim->prox;
        
    free(c);

    return a;
}

void fila_Imprime(Fila* f) {
    assert(f);

    for (Celula* c = f->prim; c != NULL; c = c->prox) {
        imprimeAmostra(c->amostra);
    }
}