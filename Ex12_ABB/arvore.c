#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "arvore.h"

struct arvore {
    Aluno* a;
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
        Arv* arv = malloc(sizeof(Arv*))
    }
}

/**
 * @brief Imprime a árvore na notação de pré-ordem.
 * @param r a árvore (raiz) a ser impressa.
 */
void arv_Imprime(Arv* r);

/**
 * @brief Busca o aluno na árvore.
 * 
 * @param r A arvore (raíz) na qual o aluno será buscado.
 * @param mat A matrícula do aluno.
 * 
 * @return A subárvore contendo o aluno na raiz, ou NULL caso o aluno não esteja na árvore.
 */
Arv* arv_BuscaAluno(Arv* r, int mat);

/**
 * @brief Remove o aluno da árvore.
 * 
 * @param r a árve onde o aluno será buscado.
 * @param mat a mátricula do aluno a ser removido.
 * 
 * @return a árvore atualizada.
 */
Arv* arv_RemoveAluno(Arv* r, int mat);

/**
 * @brief Libera a memoria alocada pela árvore (sem liberar a memoria dos alunos).
 * 
 * @param r a árvore a ser liberada.
 * 
 * @return NULL.
 */
Arv* arv_Libera(Arv* r);