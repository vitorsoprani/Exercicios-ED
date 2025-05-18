//
//  matriz.c
//  TADMatriz
//
//  Created by Vitor Soprani Passamani on 14/05/2025.
//

#include <stdlib.h>
#include <assert.h>

#include "matriz.h"

struct matriz{
    int nLinhas;
    int nColunas;

    int** elementos;
};

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz* inicializaMatriz (int nlinhas, int ncolunas) {
    Matriz* m = (Matriz*)malloc(sizeof(Matriz));
    assert(m != NULL);

    m->nLinhas = nlinhas;
    m->nColunas = ncolunas;

    m->elementos = (int**)malloc(sizeof(int*) * nlinhas * ncolunas);
    assert(m->elementos != NULL);

    for (int i = 0; i < nlinhas; i++) {
        m->elementos[i] = (int*)malloc(sizeof(int) * ncolunas);
        assert(m->elementos[i] != NULL);
    }

    return m;
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento (Matriz* mat, int linha, int coluna, int elem) {
    assert(mat != NULL);
    assert(linha >= 0);
    assert(coluna >= 0);
    assert(linha < mat->nLinhas);
    assert(coluna < mat->nColunas);

    mat->elementos[linha][coluna] = elem;
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: mat nao eh modificada
 */
int recuperaElemento(Matriz* mat, int linha, int coluna) {
    assert(mat != NULL);
    assert(linha >= 0);
    assert(coluna >= 0);
    assert(linha < mat->nLinhas);
    assert(coluna < mat->nColunas);

    return mat->elementos[linha][coluna];
}

/*Retorna o numero de colunas da matriz mat
 * inputs: a matriz
 * output: o numero de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNColunas (Matriz* mat) {
    assert(mat != NULL);

    return mat->nColunas;
}

/*Retorna o numero de linhas da matriz mat
 * inputs: a matriz
 * output: o numero de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNLinhas (Matriz* mat) {
    assert(mat != NULL);

    return mat->nLinhas;
}

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada e matriz transposta existe
 */
Matriz* transposta (Matriz* mat) {
    assert(mat != NULL);

    Matriz* transp = inicializaMatriz(mat->nColunas, mat->nLinhas);

    for (int i = 0; i < recuperaNLinhas(mat); i++)
        for (int j = 0; j < recuperaNColunas(mat); j++)
            modificaElemento(transp, j, i, recuperaElemento(mat, i, j));

    return transp;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicacao
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1 correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 nao sao modificadas e a matriz multiplicacao existe
 */
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2) {
    assert(mat1 != NULL);
    assert(mat2 != NULL);
    assert(recuperaNColunas(mat1) == recuperaNLinhas(mat2));

    Matriz* multi = inicializaMatriz(recuperaNLinhas(mat1), recuperaNColunas(mat2));

    for (int i = 0; i < recuperaNLinhas(multi); i++) {
        for (int j = 0; j < recuperaNColunas(multi); j++) {
            int soma = 0;
            for (int k = 0; k < recuperaNColunas(mat1); k++) {
                soma += recuperaElemento(mat1, i, k) * recuperaElemento(mat2, k, j);
            }

            modificaElemento(multi, i, j, soma);
        }
    }

    return multi;
}

/*Imprime a matriz completa
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz* mat) {
    assert(mat != NULL);

    for (int i = 0; i < recuperaNLinhas(mat); i++) {
        // printf("\t");
        for (int j = 0; j < recuperaNColunas(mat) - 1; j++) {
            printf("%d ", recuperaElemento(mat, i, j));
        }
        printf("%d\n", recuperaElemento(mat, i, recuperaNColunas(mat) - 1));
    }
}

/*Imprime apenas uma linha da matriz
 * inputs: matriz mat e o indice da linha
 * output: nenhum
 * pre-condicao: matriz mat existe e indice eh valido na matriz
 * pos-condicao: nenhuma
 */
void imprimeLinha (Matriz* mat, int indice) {
    assert(mat != NULL);
    assert(indice >= 0);
    assert(indice < recuperaNLinhas(mat));

    for (int i = 0; i < recuperaNColunas(mat) - 1; i++)
        printf("%d ", recuperaElemento(mat, indice, i));
    printf("%d", recuperaElemento(mat, indice, recuperaNColunas(mat) - 1));
}

/*Libera toda a memoria alocada para a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: memoria ocupada por linhas e colunas liberada!
 */
void destroiMatriz (Matriz* mat) {
    if (mat != NULL) {
        for (int i = 0; i < recuperaNLinhas(mat); i++)
            free(mat->elementos[i]);
        free(mat->elementos);
        free(mat);
    }
}
