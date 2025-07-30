#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "arvore.h"

struct arvore {
    Aluno* aluno;
    Arv* esq;
    Arv* dir;
};

/**
 * @brief Inicializa uma árvore vazia. Como estamos trabalhando com uma árvore sem sentinela, retorna NULL.
 * @return A árvore.
 */
Arv* arv_Cria(void) {
    return NULL;
}

/**
 * @brief Insere um aluno na posição correta na ufes.
 * 
 * @param r Uma árvore (raiz) inicializada válida.
 * @param a o aluno a ser inserido na árvore.
 * 
 * @return A árvore com o aluno inserido na posição correta
 */
Arv* arv_Insere(Arv* r, Aluno* a) {
    assert(a != NULL);

    if (r == NULL) {
        r = (Arv*)malloc(sizeof(Arv));
        r->esq = NULL;
        r->dir = NULL;
        r->aluno = a;
        return r;
    }

    if (comparaAluno(a, r->aluno) < 0) { //Aluno a ser inserido é menor que o nó raiz
        r->esq = arv_Insere(r->esq, a);
        return r;
    }

    r->dir = arv_Insere(r->dir, a); //Maior ou igual
    return r;
}

/**
 * @brief Imprime a árvore na notação de pré-ordem.
 * @param r a árvore (raiz) a ser impressa.
 */
void arv_Imprime(Arv* r) {
    printf("<");

    if (r != NULL) {
        imprimeAluno(r->aluno);
        arv_Imprime(r->esq);
        arv_Imprime(r->dir);
    }

    printf(">");
}

void arv_ImprimeOrdenada(Arv* r) {
    if (r == NULL)
        return;

    arv_ImprimeOrdenada(r->esq);
    imprimeAluno(r->aluno);
    arv_ImprimeOrdenada(r->dir);
}


/**
 * @brief Busca o aluno na árvore.
 * 
 * @param r A arvore (raíz) na qual o aluno será buscado.
 * @param mat A matrícula do aluno.
 * 
 * @return o aluno ou NULL 
 */
Aluno* arv_BuscaAluno(Arv* r, int mat) {
    if (r == NULL)
        return NULL;
    
    if (retornaMatriculaAluno(r->aluno) > mat)
        return arv_BuscaAluno(r->esq, mat);
    
    if (retornaMatriculaAluno(r->aluno) < mat)
        return arv_BuscaAluno(r->dir, mat);
    
    return r->aluno;
}

/**
 * @brief Remove o aluno da árvore.
 * 
 * @param r a árve onde o aluno será buscado.
 * @param mat a mátricula do aluno a ser removido.
 * 
 * @return a árvore atualizada.
 */
Arv* arv_RemoveAluno(Arv* r, int mat) {
    if (r == NULL)
        return NULL;
    
    if (retornaMatriculaAluno(r->aluno) > mat) { //aluno menor que o atual
        r->esq = arv_RemoveAluno(r->esq, mat);
        return r;
    }
    
    if (retornaMatriculaAluno(r->aluno) < mat) { //aluno maior que o atual
        r->dir = arv_RemoveAluno(r->dir, mat);
        return r;
    }

    //-------aluno igual------
    if (r->dir == NULL && r->esq == NULL) { //nó folha
        free(r);
        return NULL;
    }

    if (r->dir == NULL) { //só tem filho à esquerda
        Arv* a = r->esq;
        free(r);
        return a;
    }

    if (r->esq == NULL) { //só tem filho à direita
        Arv* a = r->dir;
        free(r);
        return a;
    }

    //se o nó tiver 2 filhos:
    //encontra o antecessor
    Arv* a;
    for (a = r->esq; a->dir != NULL; a = a->dir); //o antecessor é o elemento mais à direita da subárvore à esquerda
    //troca o aluno de a com o aluno de r
    r->aluno = (Aluno*)((unsigned long int)(r->aluno) ^ (unsigned long int)(a->aluno));
    a->aluno = (Aluno*)((unsigned long int)(r->aluno) ^ (unsigned long int)(a->aluno));
    r->aluno = (Aluno*)((unsigned long int)(r->aluno) ^ (unsigned long int)(a->aluno));

    r->esq = arv_RemoveAluno(r->esq, mat);

    return r;
}

/**
 * @brief Libera a memoria alocada pela árvore (sem liberar a memoria dos alunos).
 * 
 * @param r a árvore a ser liberada.
 * 
 * @return NULL.
 */
Arv* arv_Libera(Arv* r) {
    if (r == NULL)
        return NULL;
    
    arv_Libera(r->esq);
    arv_Libera(r->dir);
    free(r);
    return NULL;
}