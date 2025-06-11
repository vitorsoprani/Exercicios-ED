#ifndef _FILA_H
#define _FILA_H

#include "amostra.h"

typedef struct fila Fila;

Fila* fila_Cria();

void* fila_Destroi(Fila* f);

void fila_Insere(Fila* f, Amostra* a);

void fila_InserePrioritario(Fila* f, Amostra* a);

Amostra* fila_Remove(Fila* f);

void fila_Imprime(Fila* f);

#endif