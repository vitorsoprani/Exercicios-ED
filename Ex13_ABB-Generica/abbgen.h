#ifndef _ABBGEN_H
#define _ABBGEN_H

typedef struct abbGen AbbGen;

/**
 * @brief Cria uma arvore binaria de busca generica inicialmente vazia (pontiero NULL);
 * 
 * @return a arvore.
 */
AbbGen* abb_Cria(void);

/**
 * @brief Função que insere um novo elemento na ṕposoicao correta na arvore.
 * 
 * @param r a raíz da arvore (válida) na qual o dado será inserido.
 * @param dado o novo dado a ser inserido (incializado e válido).
 * @param compara ponteiro para a função de compraração adequada para o dado.
 * 
 * @return a arvore atualizada com o novo dado inserido.
 */
AbbGen* abb_Insere(AbbGen* r, void* dado, int (*compara)(void*, void*));

/**
 * @brief Função que imprime a árvore em forma de lista na ordem crescente no arquivo.
 * 
 * @param r raiz da árvore a ser impressa (inicializada e válida)
 * @param imprime ponteiro para uma função de impressao correspondente ao tipo de dado armazenado na árvore.
 */
void abb_Imprime(AbbGen* r, void (*imprime)(void* dado, FILE* arq), FILE* arq);

/**
 * @brief função que liberA TODA A MEMORIA alocada pekla árvore (não libera a memoria usada pelos dados. só a memória da árvore)
 * 
 * @param r o nó raiz da árvore a ser liberada
 * @return a árvore desalocada.
 */
AbbGen* abb_Libera(AbbGen* r, void (*) (void*));

#endif