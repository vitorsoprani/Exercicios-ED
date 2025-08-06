#include <stdio.h>
#include <stdlib.h>

#include "mercado.h"

int main() {
    Mercado** mercados = (Mercado**)malloc(0); //Ambos os vetores inicam vazios
    int qtdMercados = 0;
    Produto** produtos = (Produto**)malloc(0);
    int qtdProdutos = 0;

    int opt = 0;
    while (1) {
        printf("Qual acao voce deseja realizar?\n");
        printf("[1] - Cadastrar Produto.\n");
        printf("[2] - Cadastrar Mercado.\n");
        printf("[3] - Cadastrar Filial.\n");
        printf("[4] - Adicionar Item\n");
        printf("[5] - Listar Mercados\n");
        printf("[6] - Listar Produtos\n");
        printf("[0] - Sair do programa\n");

        scanf("%d%*c", &opt);

        if (opt == 0) {
            break;  
        } else if (opt == 1) {
            char nome[100];
            float preco;
            printf("Digite o nome do produto: ");
            scanf("%99[^\n]%*c", nome);

            if (BuscaProdutoPorNome(produtos, qtdProdutos, nome) != -1) {
                printf("Produto já cadatrado.\n");
                continue;
            }
            printf("Digite o preco do produto: ");
            scanf("%f%*c", &preco);

            produtos = (Produto**)realloc(produtos, sizeof(Produto*) * (qtdProdutos + 1));

            produtos[qtdProdutos] = CriaProduto(nome, preco);
            qtdProdutos++;
        } else if (opt == 2) {
            char nome[100];
            printf("Digite o nome do mercado: ");
            scanf("%99[^\n]%*c", nome);

            if (BuscaMercadoPorNome(mercados, qtdMercados, nome) != -1) {
                printf("Mercado ja cadastrado.\n");
                continue;
            }

            mercados = (Mercado**)realloc(mercados, sizeof(Mercado*) * (qtdMercados  + 1));
            mercados[qtdMercados] = CriaMercado(nome);
            qtdMercados++;

        } else if (opt == 3) {
            char nomeMercado[100], nomeFilial[100];
            int idxMercado = 0;
            
            printf("Digite o nome do mercado: ");
            scanf("%99[^\n]%*c", nomeMercado);

            idxMercado = BuscaMercadoPorNome(mercados, qtdMercados, nomeMercado);

            if (idxMercado == -1) {
                printf("Mercado não cadastrado.\n");
                continue;
            }

            printf("Digite o nome da filial: ");
            scanf("%99[^\n]%*c", nomeFilial);

            AdicionaFilialMercado(mercados[idxMercado], nomeFilial);
        } else if (opt == 4) {
            char nomeProduto[100], nomeMercado[100], nomeFilial[100];
            int quantidade = 0, idxMercado = -1, idxProduto = -1;

            printf("Digite o nome do produto: ");
            scanf("%99[^\n]%*c", nomeProduto);
            
            idxProduto = BuscaProdutoPorNome(produtos, qtdProdutos, nomeProduto);

            if (idxProduto < 0) {
                printf("Produto não cadastrado.\n");
                continue;
            }
            printf("Digite a quantidade: ");
            scanf("%d%*c", &quantidade);
            
            printf("Digite o nome do mercado: ");
            scanf("%99[^\n]%*c", nomeMercado);

            idxMercado = BuscaMercadoPorNome(mercados, qtdMercados, nomeMercado);

            if (idxMercado) {
                printf("Mercado não cadastrado.\n");
                continue;
            }

            printf("Digite o nome da filial: ");
            scanf("%99[^\n]%*c", nomeFilial);

            AdicionaItemFilialMercado(mercados[idxMercado], CriaItem(produtos[idxProduto], quantidade), nomeFilial);
        } else if (opt == 5) {
            printf("Mercados cadastrados:\n");
            for (int i = 0; i < qtdMercados; i++) {
                ImprimeMercado(mercados[i]);
            }
        } else if (opt == 6) {
            printf("Lista de Produtos no catálogo:\n");
            for (int i = 0; i < qtdProdutos; i++) {
                printf("\t");
                ImprimeProduto(produtos[i]);
                printf("\n");
            }
        }
    }

    for (int i = 0; i < qtdMercados; i++) {
        DestroiMercado(mercados[i]);
    }

    for (int i = 0; i < qtdProdutos; i++) {
        DestroiProduto(produtos[i]);
    }

    free(mercados);
    free(produtos);
    return 0;
}