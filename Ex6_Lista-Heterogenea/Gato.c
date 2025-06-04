#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "Gato.h"

struct gato {
    char* nome;
    enum Personalidade personalidade;
};

Gato* inicGato(char* nome, enum Personalidade personalidade) {
    Gato* g = (Gato*)malloc(sizeof(Gato));
    assert(g != NULL);

    g->nome = strdup(nome);
    g->personalidade = personalidade;

    return g;
}

void liberaGato(Gato* g) {
    if (g == NULL)
        return;
    free(g->nome);
    free(g);
}

void atribuiNivelAgressividadeGato(Gato* g, enum Personalidade p) {
    assert(g != NULL);

    g->personalidade = p;
}

enum Personalidade getPersonalidadeGato(Gato* g) {
    assert(g);
    return g->personalidade;
}

void imprimeGato(void* g) {
    assert(g);

    printf("Gato: %s\n", ((Gato*)g)->nome);
}