#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pilhaDupla.h"

struct indicePilha{
    int topo; //aponta sempre para a primeira posição vazia
    int base;
};

struct pilhaDupla{
    int itens[MAX_TAM];

    IndicePilha pilha0;
    IndicePilha pilha1;
};

PilhaDupla* criaPilhaDupla() {
    PilhaDupla* p = (PilhaDupla*)malloc(sizeof(PilhaDupla));
    assert(p != 0);

    //Cresce para a esquerda
    p->pilha0.base = 0;
    p->pilha0.topo = 0;

    //Cresce para a esquerda
    p->pilha1.base = MAX_TAM - 1;
    p->pilha1.topo = MAX_TAM - 1;

    return p;
}

int pushPilha(PilhaDupla* p, int nPilha, int n) {
    assert(p != 0);

    int nElementos = (p->pilha0.topo - p->pilha0.base) + (p->pilha1.base - p->pilha1.topo);
    
    if (nElementos >= MAX_TAM)
        return 0;

    if (nPilha == 0) {
        p->itens[p->pilha0.topo] = n;
        p->pilha0.topo++;
    } else if (nPilha == 1){
        p->itens[p->pilha1.topo] = n;
        p->pilha1.topo--;
    } else {
        return 0;
    }
    
    return 1;
}

int popPilha(PilhaDupla* p, int nPilha, int* n) {
    assert(p != 0);

    if (nPilha == 0) {
        p->pilha0.topo--;
        *n = p->itens[p->pilha0.topo];
    } else if (nPilha == 1){
        p->pilha1.topo++;
        *n = p->itens[p->pilha1.topo];
    } else {
        return 0;
    }
    
    return 1;
}

void printPilha(PilhaDupla* p, int nPilha) {
    if (nPilha == 0)
        for (int i = p->pilha0.base; i < p->pilha0.topo; i++)
            printf("%d ", p->itens[i]);
    else
        for (int i = p->pilha1.base; i > p->pilha1.topo; i--)
            printf("%d ", p->itens[i]);
}

void liberaPilha(PilhaDupla* p) {
    free(p);
}
