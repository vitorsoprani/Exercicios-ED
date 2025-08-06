#include <stdio.h>

#include "pilhaDupla.h"

int main() {
    PilhaDupla* p = criaPilhaDupla();

    printf("pilha 0:");
    printPilha(p, 0);
    printf("\n");

    printf("pilha 1:");
    printPilha(p, 1);
    printf("\n");
    
    int i;
    for (i = 1; i <= 30; i++) {
        pushPilha(p, 0, i);
    }

    while (pushPilha(p, 1, i))
        i++;

    printf("pilha 0:");
    printPilha(p, 0);
    printf("\n");

    printf("pilha 1:");
    printPilha(p, 1);
    printf("\n");

    liberaPilha(p);
    return 0;
}