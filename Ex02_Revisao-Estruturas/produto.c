#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "produto.h"

struct Produto {
    char* nome;
    float preco;
};

Produto* CriaProduto(char* nome, float preco) {
    assert(nome != NULL);

    Produto* p = (Produto*)malloc(sizeof(Produto));
    assert(p != NULL);

    p->nome = (char*)malloc(sizeof(char) * (strlen(nome) + 1));
    assert(p->nome != NULL);
   
    strcpy(p->nome, nome);
    p->preco = preco;

    return p;
}

void DestroiProduto(Produto* p) {
    if (p != NULL) {
        free(p->nome);
        free(p);
    }
}

Produto* LeProduto() {
    char nome[100];
    float preco = 0;

    scanf(" %99[^\n]%*c", nome);
    scanf(" %f%*c", &preco);

    return CriaProduto(nome, preco);
}

void ImprimeProduto(Produto* p) {
    assert(p != NULL);
    assert(p->nome != NULL);

    printf("%s, valor unitario: %.2f", p->nome, p->preco);
}

float GetPrecoProduto(Produto* p) {
    assert(p != NULL);

    return p->preco;
}

int BuscaProdutoPorNome(Produto** vet, int n, char* nome) {
    for (int i = 0; i < n; i++) {
        if (strcmp(vet[i]->nome, nome) == 0)
            return i;
    }

    return -1;
}