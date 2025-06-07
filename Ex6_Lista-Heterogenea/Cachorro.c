#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "Cachorro.h"

struct cachorro {
    char* nome;
    enum Personalidade personalidade;
};

Cachorro* inicCachorro(char* nome, enum Personalidade personalidade) {
    Cachorro* c = (Cachorro*)malloc(sizeof(Cachorro));
    assert(c != NULL);

    c->nome = strdup(nome);
    c->personalidade = personalidade;

    return c;
}

void liberaCachorro(Cachorro* c) {
    if (c == NULL)
        return;
    free(c->nome);
    free(c);
}

void atribuiNivelAgressividadeCachorro(Cachorro* c, enum Personalidade p) {
    assert(c != NULL);

    c->personalidade = p;
}

enum Personalidade getPersonalidadeCachorro(Cachorro* c) {
    assert(c);
    return c->personalidade;
}

void imprimeCachorro(void* c) {
    assert(c);
    printf("Cachorro: %s\n", ((Cachorro*)c)->nome);
}


int comparaCachorro(void* cachorro, void* nome) {
    return strcmp(((Cachorro*)cachorro)->nome, (char*)nome) == 0;
}

char* getNomeCachorro(Cachorro* c) {
    assert(c);

    return c->nome;
}