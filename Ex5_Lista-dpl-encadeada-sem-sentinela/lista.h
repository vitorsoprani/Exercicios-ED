#ifndef _LISTA_H
#define _LISTA_H

#include "produto.h"

typedef struct lista Lista;

Lista* lista_Cria();

Lista* lista_InsereNoInicio(Lista* l, Produto* p);

Lista* lista_InsereNoFinal(Lista* l, Produto* p);

Lista* lista_Busca(Lista* l, void* chave, int(*compara) (Produto*, void*));

Produto* lista_Remove(Lista** l, void* chave, int(*compara) (Produto*, void*));

void lista_Imprime(Lista* l);

Lista* lista_Destroi(Lista* l);

#endif