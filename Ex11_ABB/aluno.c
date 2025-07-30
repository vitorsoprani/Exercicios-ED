//
//
// Criado por Thais Gomes no dia 25/06/2025
//
//

#include "aluno.h"
#include <assert.h>

struct aluno{
    char* nome;
    int matricula;
};

Aluno* inicializaAluno(char* nome, int mat){
    Aluno* a = malloc(sizeof(struct aluno));
    a->nome = strdup(nome);
    a->matricula = mat;
    return a;
}

int retornaMatriculaAluno(Aluno* aluno){
    return aluno->matricula;
}

void imprimeAluno(Aluno* aluno){
    if (aluno == NULL)
        printf("{-;-}");
    else
        printf("{%s;%d}", aluno->nome, aluno->matricula);
}

void liberaAluno(Aluno* aluno){
    if(aluno != NULL){
        free(aluno->nome);
        free(aluno);
    }
}

int comparaAluno(Aluno* a1, Aluno* a2) {
    assert(a1 != NULL);
    assert(a2 != NULL);
    return a1->matricula - a2->matricula;
}
