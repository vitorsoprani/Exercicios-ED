#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

int main() {
    Arv* arvore = arv_Cria();
    Aluno* aluno1 = inicializaAluno("a1", 1);
    Aluno* aluno2 = inicializaAluno("a2", 2);
    Aluno* aluno3 = inicializaAluno("a3", 3);
    Aluno* aluno4 = inicializaAluno("a4", 4);
    Aluno* aluno5 = inicializaAluno("a5", 5);
    Aluno* aluno6 = inicializaAluno("a6", 6);
    Aluno* aluno7 = inicializaAluno("a7", 7);
    Aluno* aluno8 = inicializaAluno("a8", 8);

    arv_Imprime(arvore);
    printf("\n");

    arvore = arv_Insere(arvore, aluno7);
    arvore = arv_Insere(arvore, aluno1);
    arvore = arv_Insere(arvore, aluno4);
    arvore = arv_Insere(arvore, aluno6);
    arvore = arv_Insere(arvore, aluno2);
    arvore = arv_Insere(arvore, aluno3);
    arvore = arv_Insere(arvore, aluno5);
    arvore = arv_Insere(arvore, aluno8);

    arv_Imprime(arvore);
    printf("\n");

    arv_ImprimeOrdenada(arvore);
    printf("\n");

    imprimeAluno(arv_BuscaAluno(arvore, 1));
    printf("\n");
    imprimeAluno(arv_BuscaAluno(arvore, 10));
    printf("\n");

    arv_RemoveAluno(arvore, 7);
    arv_RemoveAluno(arvore, 5);
    arv_RemoveAluno(arvore, 1);
    arv_RemoveAluno(arvore, 4);
    arv_RemoveAluno(arvore, 20);
    
    arv_Imprime(arvore);
    printf("\n");

    arv_ImprimeOrdenada(arvore);
    printf("\n");
    
    arvore = arv_Libera(arvore);

    liberaAluno(aluno1);
    liberaAluno(aluno2);
    liberaAluno(aluno3);
    liberaAluno(aluno4);
    liberaAluno(aluno5);
    liberaAluno(aluno6);
    liberaAluno(aluno7);
    liberaAluno(aluno8);
    
    return EXIT_SUCCESS;
}