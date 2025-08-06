#ifndef _ESTOQUE_H
#define _ESTOQUE_H

#include "item.h"

typedef struct Estoque Estoque;

Estoque* CriaEstoque();

void AdicionaItemEstoque(Estoque* e, Item* i);

void DestroiEstoque(Estoque* e);

void ImprimeEstoque(Estoque* e);

#endif