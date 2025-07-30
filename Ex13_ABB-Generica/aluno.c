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
    int cr;
};

Aluno* inicializaAluno(char* nome, int mat, int cr){
    Aluno* a = malloc(sizeof(struct aluno));
    a->nome = strdup(nome);
    a->matricula = mat;
    a->cr = cr;
    return a;
}

int retornaMatriculaAluno(Aluno* aluno){
    return aluno->matricula;
}

char* retornaNomeAluno(Aluno* aluno){
    return aluno->nome;
}

int retornaCrAluno(Aluno* aluno){
    return aluno->cr;
}

void imprimeAluno(Aluno* aluno, FILE* arq){
    fprintf(arq, "%d %s %d\n", aluno->matricula, aluno->nome, aluno->cr);
}

void liberaAluno(Aluno* aluno){
    if(aluno != NULL){
        free(aluno->nome);
        free(aluno);
    }
}

int comparaAlunoMatricula(Aluno* a1, Aluno* a2) {
    assert(a1 != NULL);
    assert(a2 != NULL);
    return a1->matricula - a2->matricula;
}

int comparaAlunoNome(Aluno* a1, Aluno* a2) {
    assert(a1 != NULL);
    assert(a2 != NULL);
    return strcmp(a1->nome, a2->nome);
}

int comparaAlunoCr(Aluno* a1, Aluno* a2) {
    assert(a1 != NULL);
    assert(a2 != NULL);
    return a1->cr - a2->cr;
}
