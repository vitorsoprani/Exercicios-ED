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

Aluno* inicializaAluno(char* nome, int mat);
int retornaMatriculaAluno(Aluno* aluno);
void imprimeAluno(Aluno* aluno);
void liberaAluno(Aluno* aluno);

#endif