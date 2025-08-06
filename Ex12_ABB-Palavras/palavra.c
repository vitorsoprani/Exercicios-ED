/**
 * @file palavra.c
 * @author Vitor Soprani Passamani (vitor.passamani@edu.ufes.br)
 * @brief Arquivo de implementação do tipo palavra
 * @version 0.1
 * @date 2025-08-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "palavra.h"

struct palavra {
    int     freq;
    char*   string;
};

/**
 * @brief Funcao que inicializa uma palavra
 * 
 * @param palavra string representando a palavra em si
 * @param freq inteiro que representa quantas vezes a palavra aparece (usualmente inicia como 0)
 * 
 * @return Palavra* a palavra alocada e inicializada
 */
Palavra* palavra_Cria(char* palavra, int freq) {
    assert(palavra != NULL);
    assert(freq >= 0);

    Palavra* p = (Palavra*)malloc(sizeof(Palavra));
    assert(p != NULL);

    p->string = strdup(palavra);
    p->freq = freq;

    return p;
}

/**
 * @brief Retorna a string da palavra
 * 
 * @param p a palavra
 * @return char* a string
 */
char* palavra_GetStr(Palavra* p) {
    assert(p != NULL);
    return p->string;
}

/**
 * @brief Retorna a frequencia da palara
 * 
 * @param p a palvra
 * @return a frequencia
 */
int palavra_GetFrequencia(Palavra* p) {
    assert(p != NULL);
    return p->freq;
}

/**
 * @brief Compara a palavra1 com a palavra2 levando em conta a string
 * 
 * @param p1 
 * @param p2 
 * 
 * @return -1 se p1 < p2, 1 se p1 > p2 e 0 se p1 = p2
 */
int palavra_ComparaStr(Palavra* p1, Palavra* p2) {
    assert(p1 != NULL);
    assert(p2 != NULL);

    return strcmp(p1->string, p2->string);
}

/**
 * @brief Libera a memoria alocada pela palavra.
 * 
 * @param p 
 */
void palavra_Libera(Palavra* p) {
    if (p != NULL) {
        free(p->string);
        free(p);
    }
}

/**
 * @brief Incrementa em 1 a frequencia da palavra.
 * 
 * @param p 
 */
void palavra_IncrementaFrequencia(Palavra* p) {
    assert(p != NULL);

    p->freq += 1;
}