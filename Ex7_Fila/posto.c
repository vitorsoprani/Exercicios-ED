
//Define o limite entre positivo e negativo
//Amostras com carga viral >= LIMETE_CARGA_VIRAL são consideradas POSITIVAS
//Amostras com carga viral < LIMETE_CARGA_VIRAL são consideradas NEGATIVAS
#define LIMITE_CARGA_VIRAL 500

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "posto.h"
#include "fila.h"

struct posto {
    char* nome;
    Fila* naoProcessadas;
    Fila* positivas;
    Fila* negativas;
};

/* Cria um posto de saúde, ainda vazio, com as 3 filas, vazias
* inputs: nome do posto de saúde.
* output: posto alocado e vazio, com filas de amostras ainda vazias
* pre-condicao: nao tem
* pos-condicao: posto alocado e vazio, com filas de amostras alocadas e vazias
 */
Posto* inicPosto(char* nome) {
    Posto* p = (Posto*)malloc(sizeof(Posto));
    assert(p);

    p->nome = strdup(nome);

    p->naoProcessadas = fila_Cria();
    p->positivas = fila_Cria();
    p->negativas = fila_Cria();

    return p;
}

/* Imprime os dados do Posto no seguinte formato:
 
 Dados do Posto: <nome do posto>
 Amostras não processadas
 <fila de amostras não processadas - do início ao fim>
 
 Amostras com resultados positivos
 <fila de amostras positivas - do início ao fim>
 
 Amostra com resultados negativos
 <fila de amostras negativas - do início ao fim>
 
* inputs: referencia para o posto
* output: nenhum
* pre-condicao: posto alocado
* pos-condicao: dados do posto não são alterados
 */
void imprimePosto(Posto* posto) {
    assert(posto);
// Dados do Posto: Posto de Jardim Camburi
// Amostras não processadas
// Nome do dono da amostra: Joao, carga viral: 249, idade: 64, resultado: NEGATIVO
// Nome do dono da amostra: Patricia, carga viral: 807, idade: 44, resultado: NEGATIVO
// Nome do dono da amostra: Maria, carga viral: 73, idade: 20, resultado: NEGATIVO

// Amostras com resultados positivos

// Amostra com resultados negativos
    printf("Dados do posto: %s\n", posto->nome);
    printf("Amostras não processadas\n");
    fila_Imprime(posto->naoProcessadas);
    printf("\n");

    printf("Amostras com resultados positivos\n");
    fila_Imprime(posto->positivas);
    printf("\n");

    printf("Amostras com resultados negativos\n");
    fila_Imprime(posto->negativas);
    printf("\n");

}

/* Simula a realização de uma coleta de material para teste
 * A função deve criar uma amostra e fazer as devidas atribuições à amostra
 * Deve-se inserir a amostra na fila de "não processados"
 * ATENÇÃO: se a pessoa for idosa (idade>=60), ela deve ir para o início da fila de não processados
* inputs: referência para o posto de saúde, o nome do dono da coleta e a idade da pessa
* output: nenhum
* pre-condicao: posto válido, nome da pessoa válido
* pos-condicao: Amostra alocada e inserida na fila de amostras não processadas
 */
void realizaColeta(Posto* posto, char* pessoa, int idade) {
    assert(posto);

    Amostra* a = inicAmostra(pessoa, idade);

    if (idade >= 60)
        fila_InserePrioritario(posto->naoProcessadas, a);
    else
        fila_Insere(posto->naoProcessadas, a); 
}


/* Essa função simula o processamento (testagem) das amostras e atualiza os resultados nas amostras. Deve-se usar a constante LIMITE_CARGA_VIRAL para definir positivo e negativo.
* inputs: referência do posto de saúde.
* output: nenhum
* pre-condicao: posto válido
* pos-condicao: amostras foram devidamente processadas; fila de amostras não processadas deve ficar vazia; fila de amostras positivas deve conter as amostras que testaram positivo (idosos na frente); fila de amostras negativas deve conter as amostras que testaram negativo (idosos na frente).
 */
void processaLoteAmostras(Posto* posto) {
    assert(posto);

    Amostra* a = fila_Remove(posto->naoProcessadas);

    while (a != NULL) {
        if (retornaCargaViral(a) > LIMITE_CARGA_VIRAL)
            fila_Insere(posto->positivas, a);
        else
            fila_Insere(posto->negativas, a);
    
        a = fila_Remove(posto->naoProcessadas);    
    }
    
}

/* Libera toda a memória alocada para o posto de saúde
* inputs: referência do posto de saúde.
* output: nenhum
* pre-condicao: posto válido
* pos-condicao: Memória para a string nome liberada; memória para as 3 filas liberada, memoria do posto liberada
 */
void liberaPosto(Posto* posto) {
    if (posto != NULL) {
        fila_Destroi(posto->naoProcessadas);
        fila_Destroi(posto->positivas);
        fila_Destroi(posto->negativas);
        free(posto->nome);
        free(posto);
    }
}