#ifndef _ITEM_H
#define _ITEM_H

#include "produto.h"

typedef struct Item Item;

Item* CriaItem(Produto* p, int qtd);

Item* LeItem();

void DestroiItem(Item* i);

void ImprimeItem(Item* i);

float GetValorItem(Item* i);

#endif
