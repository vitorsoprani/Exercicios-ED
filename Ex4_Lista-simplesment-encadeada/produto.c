/**
 * Código simplificado que representa a estrutura e funções básicas do tipo produto.
 * 
 * Autor: Vitor Soprani Passamani.
 * Data: 21/05/1015
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <assert.h>

 #include "produto.h"

struct produto{
    int codigo;
    char* nome;
    float preco;
};

Produto* prod_Cria(int codigo, char* nome, float preco) {
    Produto* p = (Produto*)malloc(sizeof(Produto));
    assert(p != NULL);

    p->nome = (char*)malloc(sizeof(char) * (strlen(nome) + 1));
    assert(p->nome != NULL);

    strcpy(p->nome, nome);
    p->codigo = codigo;
    p->preco = preco;

    return p;
}

void prod_Destroi(Produto* p) {
    if (p != NULL) {
        free(p->nome);
        free(p);
    }
}

void prod_Imprime(Produto* p) {
    printf("Produto: %s\n", prod_GetNome(p));
    printf("\tPreco:%.2f\n", prod_GetPreco(p));
    printf("\tCodigo:%d\n", prod_GetCodigo(p));
}

int prod_ComparaPorNome(Produto* p, void* chave) {
    assert(p != NULL);
    assert(chave != NULL);

    return strcmp(p->nome, (char*)chave) == 0;
}

int prod_ComparaPorCodigo(Produto* p, void* chave) {
    assert(p != NULL);
    assert(chave != NULL);

    return p->codigo == *(int*)chave;
}

char* prod_GetNome(Produto* p) {
    assert(p != NULL);

    return p->nome;
}

float prod_GetPreco(Produto* p) {
    assert(p != NULL);

    return p->preco;
}

int prod_GetCodigo(Produto* p) {
    assert(p != NULL);

    return p->codigo;
}