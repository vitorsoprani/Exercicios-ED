#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "filial.h"
#include "estoque.h"

struct Filial {
    char* nome;

    Estoque* estoque;
};

Filial* CriaFilial(char* nome) {
    assert(nome != NULL);

    Filial* f = (Filial*)malloc(sizeof(Filial));
    assert(f != NULL);

    f->estoque = CriaEstoque();

    f->nome = (char*)malloc(sizeof(char) * (strlen(nome) + 1));
    assert(nome != NULL);
    
    strcpy(f->nome, nome);

    return f;
}

void DestroiFilial(Filial* f) {
    if (f != NULL) {
        free(f->nome);
        DestroiEstoque(f->estoque);

        free(f);
    }
}

void ImprimeFilial(Filial* f) {
    assert(f != NULL);

    printf("\t\t\t Filial: %s\n", f->nome);
    ImprimeEstoque(f->estoque);
}

char* GetNomeFilial(Filial* f);

void AdicionaItemFilial(Filial* f, Item* i) {
    assert(f != NULL);
    assert(i != NULL);

    AdicionaItemEstoque(f->estoque, i);
}

int BuscaFilialPorNome(Filial** vet, int n, char* nome) {
    for(int i = 0; i < n; i++) {
        if (strcmp(vet[i]->nome, nome) == 0)
            return i;
    }

    return -1;
}