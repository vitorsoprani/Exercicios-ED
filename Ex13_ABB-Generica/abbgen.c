#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "abbgen.h"

struct abbGen {
    void*   dado;
    AbbGen* esq;
    AbbGen* dir;
};

AbbGen* abb_Cria(void) {
    return NULL;
}

AbbGen* abb_Insere(AbbGen* r, void* dado, int (*compara)(void*, void*)) {
    assert(dado != NULL);

    if (r == NULL) {
        r = (AbbGen*)malloc(sizeof(AbbGen));
        
        r->esq = NULL;
        r->dir = NULL;

        r->dado = dado;
        return r;
    }

    if (compara(dado, r->dado) < 0) { //o dado a ser inserido é menor que o dado no nó atual
        r->esq = abb_Insere(r->esq, dado, compara);
        return r;
    }

    //insere na direita se for maior ou igual.
    r->dir = abb_Insere(r->dir, dado, compara);
    return r;
}

void abb_Imprime(AbbGen* r, void (*imprime)(void* dado, FILE* arq), FILE* arq) {
    if (r == NULL)
        return;
    
    abb_Imprime(r->esq, imprime, arq);
    imprime(r->dado, arq);
    abb_Imprime(r->dir, imprime, arq);
}

AbbGen* abb_Libera(AbbGen* r, void (*libera)(void*)) {
    if (r == NULL)
        return NULL;

    abb_Libera(r->esq, libera);
    abb_Libera(r->dir, libera);
    libera(r->dado);
    free(r);

    return NULL;
}