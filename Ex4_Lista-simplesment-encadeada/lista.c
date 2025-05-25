#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "lista.h"

typedef struct celula Celula;
struct celula{
    Produto* produto;

    Celula* prox;
};

Celula* celula_Cria(){
    Celula* c = (Celula*)malloc(sizeof(Celula));
    assert(c != NULL);

    c->produto = NULL;
    c->prox = NULL;

    return c;
}

struct lista{
    Celula* prim;
    Celula* ult;
};

Lista* lista_Cria() {
    Lista* l = (Lista*)malloc(sizeof(Lista));
    l->prim = NULL;
    l->ult = NULL;
    assert(l != NULL);

    return l;
}

void lista_InsereNoInicio(Lista* l, Produto* p) {
    assert(l != NULL);
    assert(p != NULL);

    Celula* c = celula_Cria();
    c->produto = p;
    c->prox = l->prim;
    l->prim = c;

    if (l->ult == NULL)
        l->ult = c;
}

void lista_InsereNoFinal(Lista* l, Produto* p) {
    assert(l != NULL);
    assert(p != NULL);

    Celula* c = celula_Cria();
    c->produto = p;
    
    if (l->ult == NULL) {
        l->ult = c;
        l->prim = c;
    } else {
        l->ult->prox = c;
        l->ult = c;
    }
}

Produto* lista_Remove(Lista* l, void* chave, int(*compara) (Produto*, void*)) {
    assert(l != NULL);
    assert(chave != NULL);

    Celula* ant = NULL;
    Celula* atual = l->prim;

    Produto* p = NULL;

    while(atual != NULL && !compara(atual->produto, chave)) {
        ant = atual;
        atual = atual->prox;
    }

    if (l->prim == NULL) //Lista vazia;
        return NULL;
    
    if (atual == NULL) //Produto não está na lista;
        return NULL;
    
    if (l->prim == l->ult) { //Produto é o único na lista;
        l->prim = l->ult = NULL;
    } else if (l->prim == atual) { //Produto é o primeiro na lista;
        l->prim = atual->prox;
    } else if (l->ult == atual) { //Produto é o ultimo na lista;
        l->ult = ant;
        ant->prox = atual->prox;
    } else { //Produto é um elemento qualquer na lista;
        ant->prox = atual->prox;
    }

    p = atual->produto;
    free(atual);
    
    return p;
}
void lista_Imprime(Lista* l) {
    printf("Produtos na lista: \n");
    for (Celula* c = l->prim; c != NULL; c = c->prox)
        prod_Imprime(c->produto);
}

void lista_Destroi(Lista* l) {
    assert(l != NULL);

    Celula* c = l->prim;
    Celula* prox = NULL;

    while (c != NULL) {
        prox = c->prox;
        free(c);

        c = prox;
    }

    free(l);
}