#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "lista.h"

struct lista{
    Produto* produto;

    Lista* ant;
    Lista* prox;
};

Lista* lista_Cria() {
    return NULL; //A lista inicia vazia;
}

Lista* lista_InsereNoInicio(Lista* l, Produto* p) {
    assert(p != NULL);

    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->produto = p;
    novo->ant = NULL;
    novo->prox = l;

    if (l != NULL)
        l->ant = novo;

    return novo;
}

Lista* lista_InsereNoFinal(Lista* l, Produto* p) {
    assert(p != NULL);

    Lista* prim = l;
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    
    novo->produto = p;
    novo->prox = NULL;

    if(l == NULL)
        return novo;

    while(l->prox != NULL)
        l = l->prox;
    
    l->prox = novo;
    novo->ant = l;

    return prim;
}

Lista* lista_Busca(Lista* l, void* chave, int(*compara) (Produto*, void*)) {
    assert(chave != NULL);

    for (Lista* aux = l; aux != NULL; aux = aux->prox) {
        if (compara(aux->produto, chave))
            return aux;
    }

    return NULL;
}

Produto* lista_Remove(Lista** l, void* chave, int(*compara) (Produto*, void*)) {
    assert(l != NULL);

    Lista* aux = NULL;
    Produto* p = NULL;
    
    while ((aux = lista_Busca(*l, chave, compara)) != NULL) {
        if (aux == *l)
            *l = (*l)->prox;
        else
            aux->ant->prox = aux->prox;
        
        if (aux->prox != NULL)
            aux->prox->ant = aux->ant;
        
        p = aux->produto;

        free(aux);
    }

    return p;
}

void lista_Imprime(Lista* l) {
    printf("Produtos na lista: \n");
    if(l == NULL) return;

    while (l != NULL) {
        prod_Imprime(l->produto);
        l = l->prox;
    }
}

Lista* lista_Destroi(Lista* l) {
    if (l == NULL) return NULL;
    
    while (l != NULL) {
        l = l->prox;
        free(l->ant);
    }

    return NULL;
}