/**
 * @file arvore.h
 * @author Vitor Soprani Passamani (vitor.passamani@edu.ufes.br)
 * @brief Arquivo de cabeçãlho para a bibblioteca de árvore binária de busca
 * @version 0.1
 * @date 2025-08-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _ARVORE_H
#define _ARVORE_H

#include "palavra.h"

typedef struct arvore Arv;

/**
 * @brief Inicializa uma árvore inicalmente vazia;
 * 
 * @return Arv* 
 */
Arv* arv_Cria();

/**
 * @brief Insere uma palavra na posição correta na árvore.
 * 
 * @param r A raiz da árvore onde a palavra será inserida (válida e inicializad).
 * @param palavra A palavra a ser inserida (Válida e inicializad).
 * 
 * @return 1 se a palvra ja existia na árvore e 0 caso contrário
 */
int arv_InserePalavra(Arv* r, Palavra* palavra);

/**
 * @brief Libera a memoria alocada pela arvore
 * 
 * @param r raiz da arvore a ser liberda
 * @return a arvore desalocad (NULL). 
 */
Arv* arv_Libera(Arv* r);

#endif