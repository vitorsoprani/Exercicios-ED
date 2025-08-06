#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

Produto* LeProduto();

int main() {
    Produto** produtos = (Produto**)malloc(0);
    int qtdProdutos = 0;

    Lista* lista = lista_Cria();

    int opt = -1;
    while(1) {
        printf("Escolha uma operacao:\n");
        printf("1 - Cadastrar novo produto;\n");
        printf("2 - Listar produtos cadastrados;\n");
        printf("3 - Inserir produto no inicio da lista;\n");
        printf("4 - Inserir produto no final da lista;\n");
        printf("5 - Listar lista;\n");
        printf("6 - Remover produto da lista\n");
        printf("0 - Sair.\n");
        printf("Operacao: ");

        scanf("%d%*c", &opt);

        if (opt == 0) break;

        if (opt == 1) {
            qtdProdutos++;
            produtos = (Produto**)realloc(produtos, sizeof(Produto*) * qtdProdutos);
            produtos[qtdProdutos - 1] = LeProduto();
        } else if (opt == 2) {
            printf("Produtos cadastrados:\n");
            for (int i = 0; i < qtdProdutos; i++)
                prod_Imprime(produtos[i]);
        } else if (opt == 3) {
            printf("Digite o codigo do produto a ser inserido na lista:");
            int codigo = 0;
            scanf("%d%*c", &codigo);

            int sucesso = 0;
            for (int i = 0; i < qtdProdutos; i++) {
                if (prod_ComparaPorCodigo(produtos[i], &codigo)) {
                    lista_InsereNoInicio(lista, produtos[i]);
                    sucesso = 1;
                }
            }

            if (! sucesso)
                printf("Produto não cadastrado\n");
        } else if (opt == 4) {
            printf("Digite o codigo do produto a ser inserido na lista:");
            int codigo = 0;
            scanf("%d%*c", &codigo);

            int sucesso = 0;
            for (int i = 0; i < qtdProdutos; i++) {
                if (prod_ComparaPorCodigo(produtos[i], &codigo)) {
                    lista_InsereNoFinal(lista, produtos[i]);
                    sucesso = 1;
                }
            }

            if (! sucesso)
                printf("Produto não cadastrado\n");
        } else if (opt == 5) {
            lista_Imprime(lista);
        } else if (opt == 6) {
            printf("Voce deseja buscar o produto por:\n");
            printf("1 - Nome\n");
            printf("2 - Codigo\n");
            printf("Opcao: ");

            scanf("%d%*c", &opt);

            Produto* p = NULL;
            if (opt == 1) {
                char nome[100];
                scanf("%99[^\n]%*c", nome);

                p = lista_Remove(lista, nome, prod_ComparaPorNome);
            } else if (opt == 2) {
                int codigo;
                scanf("%d%*c", &codigo);

                p = lista_Remove(lista, &codigo, prod_ComparaPorCodigo);
            }

            if (p == NULL) {
                printf("Produto nao encontrado na lista.\n");
                continue;
            }

            printf("Produto removido:\n");
            prod_Imprime(p);
        }
    }

    lista_Destroi(lista);

    for (int i = 0; i < qtdProdutos; i++)
        prod_Destroi(produtos[i]);
    free(produtos);
}

Produto* LeProduto() {
    int codigo = 0;
    float preco = 0;
    char nome[100];

    printf("Codigo: ");
    scanf("%d%*c", &codigo);
    printf("Nome: ");
    scanf("%100[^\n]%*c", nome);
    printf("Preco: ");
    scanf("%f%*c", &preco);

    return prod_Cria(codigo, nome, preco);
}
