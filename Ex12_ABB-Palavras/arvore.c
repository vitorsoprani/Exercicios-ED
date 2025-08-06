/**
 * @file arvore.c
 * @author vitor sorpani passamani (vitor.passamani@edu.ufes.br)
 * @brief arquivo de implementação da arvore binaria de busca de palavras
 * @version 0.1
 * @date 2025-08-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdlib.h>
#include <assert.h>

#include "arvore.h"

typedef struct {
    Palavra* p;
    Node* esq;
    Node* dir;
} Node;

struct arvore {
    Node* raiz
};

/**
 * @brief Inicializa uma árvore inicalmente vazia;
 * 
 * @return Arv* 
 */
Arv* arv_Cria() {
    Arv* a = (Arv*)malloc(sizeof(Arv));
    assert(a != NULL);

    a->raiz = NULL;

    return a;
}

/**
 * @brief funcao recursiva que efetivamente insere a palavra na arvore
 * 
 * @param r a raiz da arvore atualizada 
 */
static Node* node_InserePalavra(Node* r, Palavra* p) {
    if (r == NULL)
        return r;
    
    if (palavra_ComparaStr(r->p, p) < 0) {
        r->dir = node_InserePalavra(r->dir, p);
        return r;
    }

    if (palavra_ComparaStr(r->p, p) > 0) {
        r->esq = node_InserePalavra(r->esq, p);
        return r;
    }

    palavra_IncrementaFrequencia(r->p);
    return r;
}

/**
 * @brief Insere uma palavra na posição correta na árvore.
 * 
 * @param r A raiz da árvore onde a palavra será inserida (válida e inicializad).
 * @param palavra A palavra a ser inserida (Válida e inicializad).
 * 
 * @return 1 se a palvra ja existia na árvore e 0 caso contrário
 */
int arv_InserePalavra(Arv* r, Palavra* palavra);

/**
 * @brief Libera a memoria alocada pela arvore
 * 
 * @param r raiz da arvore a ser liberda
 * @return a arvore desalocad (NULL). 
 */
Arv* arv_Libera(Arv* r);