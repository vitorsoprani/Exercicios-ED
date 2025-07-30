//
//
// Criado por Thais Gomes no dia 25/06/2025
//
//

#ifndef aluno_h
#define aluno_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno* inicializaAluno(char* nome, int mat, int cr);
char* retornaNomeAluno(Aluno* aluno);
int retornaMatriculaAluno(Aluno* aluno);
int retornaCrAluno(Aluno* aluno);
void imprimeAluno(Aluno* aluno, FILE* arq);
void liberaAluno(Aluno* aluno);
int comparaAlunoMatricula(Aluno* a1, Aluno* a2);
int comparaAlunoNome(Aluno* a1, Aluno* a2);
int comparaAlunoCr(Aluno* a1, Aluno* a2);

#endif