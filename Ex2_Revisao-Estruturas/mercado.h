#ifndef _MERCADO_H
#define _MERCADO_H

#include "item.h"

typedef struct Mercado Mercado;

Mercado* CriaMercado(char* nome);

void DestroiMercado(Mercado* m);

void ImprimeMercado(Mercado* m);

void AdicionaFilialMercado(Mercado* m, char* nome);

void AdicionaItemFilialMercado(Mercado* m, Item* i, char* nomeFilial);

int BuscaMercadoPorNome(Mercado** vet, int n, char* nome);

#endif