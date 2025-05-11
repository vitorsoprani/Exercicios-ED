#ifndef _PRODUTO_H
#define _PRODUTO_H

typedef struct Produto Produto;

/**
 * @brief Função que aloca o produto dinamicamente.
 * @param nome Nome do produto.
 * @param preco Preço do produto.
 * @return O ponteiro para o produto alocado.
 */
Produto* CriaProduto(char* nome, float preco);

/**
 * @brief Função que desaloca um determinado produto. ATENÇÃO: O uso dessa função no momento errado afetará os 
 * item ligados a este produto.
 * @param p O produto a ser deslocado.
 */
void DestroiProduto(Produto* p);

/**
 * @brief Função que lê um produto da entrada padrão.
 * @return O produto já alocado pela função CriaProduto.
 */
Produto* LeProduto();

/**
 * @brief Função que imprime o produto na saída padrão.
 * @param p O produto a ser impresso.
 */
void ImprimeProduto(Produto* p);

float GetPrecoProduto(Produto* p);

int BuscaProdutoPorNome(Produto** vet, int n, char* nome);

#endif