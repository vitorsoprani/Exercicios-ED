/**
 * Código simplificado que representa a estrutura e funções básicas do tipo produto.
 * 
 * Autor: Vitor Soprani Passamani.
 * Data: 21/05/1015
 */


#ifndef _PRODUTO_H
#define _PRODUTO_H

/**
 * Definição do tipo produto.
 */
typedef struct produto Produto;

/**
 * @brief função que cria uma estrutura do tipo produto.
 * @pre Nenhuma
 * @post Estrutura do tipo Produto alocada dinamicamente.
 * 
 * @param codigo Inteiro representando o código do produto;
 * @param nome O nome do produto;
 * @param preco Float representando o preco do produto;
 * 
 * @return Ponteiro para o produto alocado.
 */
Produto* prod_Cria(int codigo, char* nome, float preco);

/**
 * @brief Função que desaloca um produto;
 * @pre O produto existe;
 * @post O produto liberado da memoria;
 * @param p Ponteiro para o produto para ser desalocado;
 */
void prod_Destroi(Produto* p);

/**
 * @brief Função que imprime um produto;
 * @pre o produto existe;
 * @post o produto é impresso na saída padrao;
 * 
 * @param p Ponteiro para o produto;
 */
void prod_Imprime(Produto* p);

/**
 * @brief Compara o produto com o nome indicado;
 * @pre o produto e o nome existem;
 * @post ---
 * 
 * @param p Ponteiro para o produto;
 * @param chave nome do produto;
 */
int prod_ComparaPorNome(Produto* p, void* chave);

/**
 * @brief Compara o produto com o código indicado;
 * @pre o produto e o nome existem
 * @post ---
 * 
 * @param p ponteiro para o produto;
 * @param chave o codigo do produto;
 */
int prod_ComparaPorCodigo(Produto* p, void* chave);

/**
 * @brief função que retorna o nome do produto;
 */
char* prod_GetNome(Produto* p);

float prod_GetPreco(Produto* p);

/**
 * @brief função que retorna o codigo do produto;
 */
int prod_GetCodigo(Produto* p);

#endif