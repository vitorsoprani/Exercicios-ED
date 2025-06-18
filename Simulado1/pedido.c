//
//  pedido.c
//  Prova1ED
//
//  Created by Vitor Soprani Passamani on 18/07/25.
//  Copyright © 2025 Vitor Soprani Passamani. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "pedido.h"

typedef struct celula TCelula;

struct celula {
    TProduto* prod;
    TCelula* prox;
};

struct pedido {
    char* dono;
    TCelula* prim;
    TCelula* ult;
};

/*----------------------------------------------------------------------
 * Inicializa o pedido de um cliente (ou seja, a sentinela!)
 * inputs: nome do dono do pedido
 * output: Pedido inicializado
 * pre-condicao: nome devidamente alocado
 * pos-condicao: Pedido inicializado contendo o nome como informado
 *---------------------------------------------------------------------- */
TPedido* InicPedido (char* dono) {
    assert(dono != NULL);

    TPedido* p = (TPedido*)malloc(sizeof(TPedido));
    p->dono = strdup(dono);
    p->prim = NULL;
    p->ult = NULL;

    return p;
}

/*----------------------------------------------------------------------
 * Inclui um produto no pedido de um cliente (ou seja, a sentinela!). Inserir ao FINAL!
 * Lembrando que um produto nao pode ser inserido mais de uma vez no pedido! Neste caso, exiba a mensagem "Produto já existe no pedido\n"
 * inputs: o pedido e o produto a ser inserido
 * output: nada
 * pre-condicao: pedido e produto foram devidamente inicializados
 * pos-condicao: produto inserido no pedido OU lista inalterada (caso o produto ja esteja na lista)
 *----------------------------------------------------------------------*/
void IncluiProdutoPedido (TPedido* pedido, TProduto* prod) {
    assert(pedido != NULL);
    assert(prod != NULL);

    TCelula* aux = pedido->prim;
    while (aux != NULL) {
        if (strcmp(RetornaNome(aux->prod), RetornaNome(prod)) == 0) //acabou a lista ou lista vazia
            break;

        aux = aux->prox;
    }

    if (aux != NULL) {//produto nao esta na lista
        printf("Produto já existe no pedido\n");
        return;
    }
    
    TCelula* c = (TCelula*)malloc(sizeof(TCelula));

    c->prod = prod;
    c->prox = NULL;

    if (pedido->ult != NULL) {
        // lista não vazia
        pedido->ult->prox = c;
    } else {
        // lista vazia
        pedido->prim = c;
    }
    //em todo caso, o produto atual vira o ultimo da fila
    pedido->ult = c;
}

/*----------------------------------------------------------------------
 * Imprime todos os dados de um pedido (o dono seguido de todos os produtos e ingredientes)
 * Caso o pedido seja novo e nao tenha ainda produtos, exibir a mensagem "Nao ha produtos neste pedido!\n"
 * inputs: o pedido
 * output: nada
 * pre-condicao: pedido devidamente inicializado
 * pos-condicao: funcao nao alterad os dados do pedido
 *----------------------------------------------------------------------*/
void ImprimePedido (TPedido* pedido) {
    assert(pedido != NULL);

    TCelula* c = pedido->prim;
    printf("\nPedido de: %s\n", pedido->dono);

    while (c != NULL) {
        ImprimeIngredientes(c->prod);
        c = c->prox;
    }
}

/*----------------------------------------------------------------------
 * Retira a unica ocorrência do produto (caso ele exista na lista).
 * Importante!!! Esta funcao nao libera o produto! Apenas o retira do pedido!
 * inputs: o pedido e, o produto a ser retirado
 * output: nada
 * pre-condicao: pedido e produto devidamente inicializados
 * pos-condicao: pedido nao contem o produto
 *----------------------------------------------------------------------*/
void RetiraProdutoPedido (TPedido* pedido, char* prod) {
    assert(pedido != NULL);
    assert(prod != NULL);

    TCelula* ant = NULL;
    TCelula* atual = pedido->prim;

    while (atual != NULL) {
        if (strcmp(RetornaNome(atual->prod), prod) == 0) //acabou a lista ou lista vazia
            break;
        //atualiza as variaveis
        ant = atual;
        atual = atual->prox;
    }
    
    if (atual == NULL) return; //lista vazia ou o produto nao está na lista
    
    if (pedido->prim == pedido->ult) //produto é o unico da lista
        pedido->prim = pedido->ult = NULL;
    else if (pedido->prim == atual) //produto é o primeiro da lista
        pedido->prim = atual->prox;
    else if (pedido->ult == atual) { //produto é o ultimo da lista
        pedido->ult = ant;
        pedido->ult->prox = NULL;
    } else //é um produto qualquer na lista
        ant->prox = atual->prox;
    
    free(atual);
}

//A função envia pedido verifica se há restrição calórica ou restrição alimentar
//Se estiver tudo ok, retira o pedido da lista (libera o pedido, porém não libera o produto) e retorna 1
//Se não estiver ok, a lista permanece a mesma e a função retorna zero

/*----------------------------------------------------------------------
 * Primeiramente, verifica se há restrição calórica ou restrição alimentar, de acordo com os parametros
 **** Para a restricao calorica, deve-se somar as calorias de todos o produtos do pedido! Caso o numero de calorias do pedido ultrapasse a restricao, exiba a mensagem : "Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!"
 ****** Para a restricao alimentar, deve-se verificar se algum produto contem como ingrediente a restricao especificada. Caso algum produto contenha o ingrediente indicado, exiba a mensagem: nPedido não Enviado! Restricao alimentar no produto: %s\n
* Se estiver tudo certo (ou seja respeitando-se as restricoes), destroi o pedido da pessoa, porém não libera os produtos) e retorna 1
 * inputs: o pedido e as restricoes calorica e alimentar
 * output: 0 (problema em algumas das restricoes). 1 (pedido enviado)
 * pre-condicao: pedido devidamente inicializado e strings validas
 * pos-condicao: se houver problema com as restricoes, o pedido deve ficar inalterado. se estiver tudo ok com as restricoes, deve destruir o pedido, porem os produtos nao devem ser liberados (pois podem estar em outros pedidos, de outras pessoas).
 *----------------------------------------------------------------------*/
int EnviaPedido (TPedido* pedido, int restricao_calorica, char* restricao_alimentar) {
    assert(pedido != NULL);

    int sumCalorias = 0;

    TCelula* aux = pedido->prim;
    while (aux != NULL) {
        sumCalorias += Calorias(aux->prod);

        if (sumCalorias > restricao_calorica) {
            printf("Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
            return 0;
        }
        if (VerificaIngrediente(aux->prod, restricao_alimentar)) {
            printf("Pedido não Enviado! Restricao alimentar no produto: %s\n", RetornaNome(aux->prod));
            return 0;
        }
        aux = aux->prox;
    }

    TCelula* ant = NULL;
    TCelula* atual = pedido->prim;

    while (atual != NULL) {
        ant = atual;
        atual = atual->prox;
        free(ant);
    }

    free(pedido->dono);
    free(pedido);

    return 1;
}