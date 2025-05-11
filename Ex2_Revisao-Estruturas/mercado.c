#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "mercado.h"
#include "filial.h"

struct Mercado{
    char* nome;
    Filial** filiais;
    int qtdFiliais;
    float valorTotal;
};

Mercado* CriaMercado(char* nome) {
    assert(nome != NULL);

    Mercado* m = (Mercado*)malloc(sizeof(Mercado));
    assert(m != NULL);

    m->nome = (char*)malloc(sizeof(char) * (strlen(nome) + 1));
    assert(m-> nome != NULL);
    strcpy(m->nome, nome);

    m->filiais = (Filial**)malloc(sizeof(Filial*) * 0); // INICIA VAZIO.

    m->valorTotal = 0;
    m->qtdFiliais = 0;

    return m;
}

void DestroiMercado(Mercado* m) {
    if (m != NULL) {
        for (int i = 0; i < m->qtdFiliais; i++)
            DestroiFilial(m->filiais[i]);
        
        free(m->filiais);
        free(m->nome);

        free(m);
    }
}

void ImprimeMercado(Mercado* m) {
    assert(m != NULL);

    printf("Nome: %s, Estoque Total: %.2f\n", m->nome, m->valorTotal);

    for (int i = 0; i < m->qtdFiliais; i++) {
        ImprimeFilial(m->filiais[i]);
    }
}

void AdicionaFilialMercado(Mercado* m, char* nome) {
    assert(m != NULL);
    
    if (BuscaFilialPorNome(m->filiais, m->qtdFiliais, nome) >= 0) {
        printf("Filial já cadastrada.\n");
        return;
    }

    m->filiais = (Filial**)realloc(m->filiais, sizeof(Filial*) * (m->qtdFiliais + 1));
    assert(m->filiais != NULL);

    m->filiais[m->qtdFiliais] = CriaFilial(nome);

    m->qtdFiliais++;
}

void AdicionaItemFilialMercado(Mercado* m, Item* i, char* nomeFilial) {
    assert(m != NULL);
    assert(i != NULL);
    assert(nomeFilial != NULL);

    int idx = BuscaFilialPorNome(m->filiais, m->qtdFiliais, nomeFilial);

    if (idx < 0){
        printf("Filial não encontrada.\n");
        return;
    }

    AdicionaItemFilial(m->filiais[idx], i);
    m->valorTotal += GetValorItem(i);
}

int BuscaMercadoPorNome(Mercado** vet, int n, char* nome) {
    for (int i = 0; i < n; i++) {
        if (strcmp(vet[i]->nome, nome) == 0)
            return i;
    }

    return -1;
}