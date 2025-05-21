#ifndef _LISTA_H
#define _LISTA_H

#include "produto.h"

typedef struct lista Lista;

Lista* lista_Cria();

void lista_InsereNoInicio(Lista* l, Produto* p);

void lista_InsereNoFinal(Lista* l, Produto* p);

Produto* lista_Remove(Lista* l, void* chave, int(*compara) (Produto*, void*));

void lista_Imprime(Lista* l);

void lista_Destroi(Lista* l);

#endif