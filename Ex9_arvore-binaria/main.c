#include <stdio.h>

#include "arvore.h"

int main() {
    Arv* arvore = arv_criavazia();

    Arv* arvore2 = arv_cria(
        inicializaAluno("aluno a", 1),
        arv_cria(
            inicializaAluno("aluno b", 2),
            arv_criavazia(),
            arv_cria(
                inicializaAluno("aluno e", 5),
                arv_criavazia(),
                arv_criavazia()
            )
        ),
        arv_cria(
            inicializaAluno("aluno c", 3),
            arv_criavazia(),
            arv_cria(
                inicializaAluno("aluno d", 4),
                arv_cria(
                    inicializaAluno("aluno f", 6),
                    arv_criavazia(),
                    arv_criavazia()
                ),
                arv_criavazia()
            )
        )
    );

    arv_imprime(arvore);
    printf("\n");

    arv_imprime(arvore2);
    printf("\n");

    printf("A matricula 12 pertence a arvore? (%d)\n", arv_pertence(arvore2, 12));
    printf("A matricula 4 pertence a arvore? (%d)\n", arv_pertence(arvore2, 4));
    printf("altura da arvore: %d\n", altura(arvore2));
    printf("ocorrencias do aluno com a matricula 12 na arvore: %d\n", ocorrencias(arvore2, 12));
    printf("ocorrencias do aluno com a matricula 6 na arvore: %d\n", ocorrencias(arvore2, 6));
    printf("pai da matricula 6: \n");
    arv_imprime(arv_pai(arvore2, 6));
    printf("\n");

    printf("pai da matricula 27: \n");
    arv_imprime(arv_pai(arvore2, 27));
    printf("\n");
    
    printf("Numero de folhas na arvore: %d\n", folhas(arvore2));

    arv_libera(arvore);
    arv_libera(arvore2);

    return 0;
}
