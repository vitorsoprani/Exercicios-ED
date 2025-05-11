#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "estoque.h"

struct Estoque {
    Item** items;

    int qtdItems;
    float valor;
};

Estoque* CriaEstoque() {
    Estoque* e = (Estoque*)malloc(sizeof(Estoque));
    assert(e != NULL);

    // Aloca o vetor de items inicialmente vazio.
    e->items = (Item**)malloc(sizeof(Item*) * 0);
    assert(e->items != NULL);

    e->valor = 0;
    e->qtdItems = 0;

    return e;
}

void AdicionaItemEstoque(Estoque* e, Item* i) {
    assert(e != NULL);
    assert(i != NULL);

    e->qtdItems++;
    e->items = (Item**)realloc(e->items, sizeof(Item*) * e->qtdItems);
    assert(e->items != NULL);

    e->items[e->qtdItems - 1] = i;

    e->valor += GetValorItem(i);
}

void DestroiEstoque(Estoque* e) {
    if (e != NULL) {
        for (int i = 0; i < e->qtdItems; i++) {
            DestroiItem(e->items[i]);
        }

        free(e->items);
        free(e);
    }
}

void ImprimeEstoque(Estoque* e) {
    assert(e != NULL);

    printf("\t\t\t Estoque: %.2f\n", e->valor);

    for (int i = 0; i < e->qtdItems; i++) {
        printf("\t\t\t\t");
        ImprimeItem(e->items[i]);
    }
}