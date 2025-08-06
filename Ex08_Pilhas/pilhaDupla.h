#ifndef _PILHA_DUPLA_H
#define _PILHA_DUPLA_H

#define MAX_TAM 100

typedef struct indicePilha IndicePilha;
typedef struct pilhaDupla PilhaDupla;

PilhaDupla* criaPilhaDupla();

int pushPilha(PilhaDupla* p, int nPilha, int n);

int popPilha(PilhaDupla* p, int nPilha, int* n);

void printPilha(PilhaDupla* p, int nPilha);

void liberaPilha(PilhaDupla* p);

#endif