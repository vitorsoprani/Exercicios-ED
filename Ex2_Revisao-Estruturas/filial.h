#ifndef _FILIAL_H
#define _FILIAL_H

#include "item.h"

typedef struct Filial Filial;

Filial* CriaFilial(char* nome);

void DestroiFilial(Filial* f);

void ImprimeFilial(Filial* f);

char* GetNomeFilial(Filial* f);

void AdicionaItemFilial(Filial* f, Item* i);

int BuscaFilialPorNome(Filial** vet, int n, char* nome);

#endif