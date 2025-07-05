#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "arvore.h"

struct arv {
    Aluno* aluno;
    Arv* sae;
    Arv* sad;
};

//Cria uma árvore vazia
Arv* arv_criavazia (void) {
    return NULL;
}

//cria uma árvore com a informação do nó raiz c, e com subárvore esquerda e e subárvore direita d
Arv* arv_cria (Aluno* c, Arv* e, Arv* d) {
    Arv* a = (Arv*)malloc(sizeof(Arv));
    assert(a != NULL);

    a->aluno = c;
    a->sae = e;
    a->sad = d;

    return a;
}

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a) {
    if (a != NULL) {
        arv_libera(a->sae);
        arv_libera(a->sad);
        liberaAluno(a->aluno);
        free(a);
    }

    return NULL;
}

//retorna true se a árvore estiver vazia e false caso contrário
int arv_vazia (Arv* a) {
    return a == NULL;
}

//indica a ocorrência (1) ou não (0) do aluno (pela chave de busca mat)
int arv_pertence (Arv* a, int mat) {
    if (a == NULL)
        return 0;

    return  retornaMatriculaAluno(a->aluno) == mat  ||
            arv_pertence(a->sae, mat)               ||
            arv_pertence(a->sad, mat);
}

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a) {
    if (arv_vazia(a)) {
        printf("<>");
        return;
    }

    printf("<"); 
    
    imprimeAluno(a->aluno);
    arv_imprime(a->sae);
    arv_imprime(a->sad);

    printf(">");
}

//retorna a mãe/pai de um dado no que contém o aluno com a matrícula mat
Arv* arv_pai (Arv* a, int mat) {
    if (a == NULL)
        return NULL;

    if ((a->sae != NULL && retornaMatriculaAluno(a->sae->aluno) == mat) ||
        (a->sad != NULL && retornaMatriculaAluno(a->sad->aluno) == mat))
        return a;

    Arv* pai = arv_pai(a->sae, mat);

    return pai != NULL ? pai : arv_pai(a->sad, mat);
}

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a) {
    if (a == NULL)
        return 0;
    
    if (a->sae == NULL && a->sad == NULL)
        return 1;

    return folhas(a->sae) + folhas(a->sad);
}   

//retorna o numero de ocorrencias de um dado aluno na árvore
int ocorrencias (Arv* a, int mat) {
    if (a == NULL)
        return 0;

    int n = retornaMatriculaAluno(a->aluno) == mat;

    return n + ocorrencias(a->sae, mat) + ocorrencias(a->sad, mat);
}

static int max (int a, int b) {
    return a > b? a : b;
}

//retorna a altura da árvore a
int altura(Arv* a) {
    if (a == NULL)
        return -1;
    
    return 1 + max(altura(a->sae), altura(a->sad));
}
