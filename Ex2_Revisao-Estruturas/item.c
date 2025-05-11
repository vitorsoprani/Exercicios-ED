#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "item.h"

struct Item{
    Produto* produto;
    int quantidade;
};

Item* CriaItem(Produto* p, int qtd) {
    assert(p != NULL);

    Item* i = (Item*)malloc(sizeof(Item));
    assert(i != NULL);

    i->quantidade = qtd;
    i->produto = p;

    return i;
}

Item* LeItem();

void DestroiItem(Item* i) {
    if (i != NULL) {
        free(i);
    }
}

void ImprimeItem(Item* i) {
    assert(i != NULL);
    assert(i->produto != NULL);

    printf(" Item: ");
    ImprimeProduto(i->produto);
    printf(", quantidade: %d\n", i->quantidade);
}

float GetValorItem(Item* i) {
    assert(i != NULL);
    
    return GetPrecoProduto(i->produto) * i->quantidade;
}
