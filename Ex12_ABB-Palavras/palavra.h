/**
 * @file palavra.h
 * @author Vitor Soprani Passamani (vitor.passamani@edu.ufes.br)
 * @brief Arquivo de cabeçalho para o struct opaco "Palavra", que contem a palavra e sua frequencia
 * @version 0.1
 * @date 2025-08-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef _PALAVRA_H
#define _PALAVRA_H

typedef struct palavra Palavra;


/**
 * @brief Funcao que inicializa uma palavra
 * 
 * @param palavra string representando a palavra em si
 * @param freq inteiro que representa quantas vezes a palavra aparece (usualmente inicia como 0)
 * 
 * @return Palavra* a palavra alocada e inicializada
 */
Palavra* palavra_Cria(char* palavra, int freq);

/**
 * @brief Retorna a string da palavra
 * 
 * @param p a palavra
 * @return char* a string
 */
char* palavra_GetStr(Palavra* p);

/**
 * @brief Retorna a frequencia da palara
 * 
 * @param p a palvra
 * @return a frequencia
 */
int palavra_GetFrequencia(Palavra* p);

/**
 * @brief Compara a palavra1 com a palavra2 levando em conta a string
 * 
 * @param p1 
 * @param p2 
 * 
 * @return -1 se p1 < p2, 1 se p1 > p2 e 0 se p1 = p2
 */
int palavra_ComparaStr(Palavra* p1, Palavra* p2);

/**
 * @brief Libera a memoria alocada pela palavra.
 * 
 * @param p 
 */
void palavra_Libera(Palavra* p);

/**
 * @brief Incrementa em 1 a frequencia da palavra.
 * 
 * @param p 
 */
void palavra_IncrementaFrequencia(Palavra* p);

#endif