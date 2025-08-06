#include <stdio.h>
#include "matriz.h"

int main() {
    Matriz* mat = NULL;

    int nLinhas, nColunas;
    
    scanf("%d %d", &nLinhas, &nColunas);

    mat = inicializaMatriz(nLinhas, nColunas);

    int elem = 0;

    for (int i = 0; i < nLinhas; i++) {
        for (int j = 0; j < nColunas; j++) {
            scanf("%d", &elem);
            modificaElemento(mat, i, j, elem);
        }
    }

    printf("-------MATRIZ ARMAZENADA-------\n");

    imprimeMatriz(mat);

    printf("-------MATRIZ IMPRESSA LINHA A LINHA-------\n");

    for (int i = 0; i < recuperaNLinhas(mat); i++) {
        imprimeLinha(mat, i);
        printf("\n-------------------------------------------\n");
    }

    Matriz* transp = transposta(mat);

    printf("-------MATRIZ TRANSPOSTA-------\n");

    imprimeMatriz(transp);

    Matriz* multi = multiplicacao(mat, transp);

    printf("-------MULTIPLICACAO DA MATRIZ PELA TRANSPOSTA-------\n");

    imprimeMatriz(multi);

    destroiMatriz(mat);
    destroiMatriz(transp);
    destroiMatriz(multi);

    return 0;
}