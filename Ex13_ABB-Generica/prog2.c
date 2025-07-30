#include <stdio.h>
#include <stdlib.h>

#include "abbgen.h"
#include "aluno.h"

int main() {
    FILE* entrada = fopen("./entrada.txt", "r");
    FILE* saida = fopen("./saida2.txt", "w");

    AbbGen* arv = abb_Cria();

    while (!feof(entrada)) {
        int mat, cr;
        char nome[100];
        fscanf(entrada, "%d %[^0-9] %d\n", &mat, nome, &cr);

        arv = abb_Insere(arv, inicializaAluno(nome, mat, cr), comparaAlunoMatricula);
    }
    
    fprintf(saida, "Arvore organizada por Nome:\n");
    abb_Imprime(arv, imprimeAluno, saida);

    fclose(entrada);
    fclose(saida);

    abb_Libera(arv, liberaAluno);

    return EXIT_SUCCESS;
}