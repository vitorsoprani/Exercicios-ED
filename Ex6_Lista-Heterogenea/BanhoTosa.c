#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "BanhoTosa.h"
#include "Gato.h"
#include "Cachorro.h"
#include "List.h"

/*Tipo que define a loja de banho e tosa (tipo opaco)
 *Cada loja deve ter os seguintes atributos:
 * * Nome da loja
 * * Uma lista de animais (gatos e cachorros) agressivos
 * * Uma lista de animais (gatos e cachorros) mansos
 * */
struct banhotosa {
    char* nome;
    List* bravos;
    List* mansos;
};


/* Cria uma loja de banho e tosa, ainda vazia, com duas listas de animais vazias
* inputs: nome da loja (char*). Esta função deve alocar dinamicamente o nome da loja.
* output: loja alocada e vazia, com listas de animais ainda vazias
* pre-condicao: nao tem
* pos-condicao: loja alocada e vazia, com listas de animais criadas e vazias  */
BanhoTosa* inicBanhoTosa(char* nome) {
    BanhoTosa* b = (BanhoTosa*)malloc(sizeof(BanhoTosa));
    assert(b);

    b->mansos = list_Init();
    b->bravos = list_Init();

    b->nome = strdup(nome);

    return b;
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraCachorro(BanhoTosa* loja, Cachorro* dog) {
    assert(loja);
    assert(dog);

    if (getPersonalidadeCachorro(dog) == MANSO) {
        list_Insert(loja->mansos, (void*)dog, imprimeCachorro, "cachorro");
    } else {
        list_Insert(loja->bravos, (void*)dog, imprimeCachorro, "cachorro");
    }
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraGato(BanhoTosa* loja, Gato* cat) {
    assert(loja);
    assert(cat);

    if (getPersonalidadeGato(cat) == MANSO) {
        list_Insert(loja->mansos, cat, imprimeGato, "gato");
    } else {
        list_Insert(loja->bravos, cat, imprimeGato, "gato");
    }
}


/* Essa função atualiza a situação de um gato na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat) {
    assert(loja);
    assert(cat);

    Cell* c;

    if ((c = list_Remove(loja->mansos, comparaGato, "gato", getNomeGato(cat)))) {
        list_Insert(loja->bravos, cat, imprimeGato, "gato");
    } else if ((c = list_Remove(loja->bravos, comparaGato, "gato", getNomeGato(cat)))) {
        list_Insert(loja->mansos, cat, imprimeGato, "gato");
    }
}

/* Essa função atualiza a situação de um cachorro na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog) {
    assert(loja);
    assert(dog);

    Cell* c;

    if ((c = list_Remove(loja->mansos, comparaCachorro, "cachorro", getNomeCachorro(dog)))) {
        list_Insert(loja->bravos, dog, imprimeCachorro, "cachorro");
    } else if ((c = list_Remove(loja->bravos, comparaGato, "cachorro", getNomeCachorro(dog)))) {
        list_Insert(loja->mansos, dog, imprimeCachorro, "cachorro");
    }
}


/* Imprime os dados da Loja (nome, e conteúdo das listas)
* inputs: referencia para a loja
* output: nenhum
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
void imprimeBanhoTosa(BanhoTosa* loja) {
    assert(loja);
    printf("Estabelecimento: %s\n", loja->nome);

    printf("Bichos Bravos: \n");
    list_Print(loja->bravos);
    printf("Bichos Mansos: \n");
    list_Print(loja->mansos);
}


/* Calcula o valor que a loja vai receber caso todos os animais tomem banho.
 Valor Gato: 30 reais, Valor Cachorro: 40 reais. Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
* inputs: referencia para a loja
* output: valor da receita
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
float calculaReceita(BanhoTosa* loja) {
    assert(loja);

    float receita = 0;
    // Contabilizando bichos mansos:
    Cell* c = list_GetCellByIndex(loja->mansos, 0);

    while(c != NULL) {
        if (strcmp(cell_GetType(c), "gato") == 0){
            receita += 30;
        } else {
            receita += 40;
        }

        c = cell_GetNext(c);
    }

    //Contabilizando bichos bravos:
    c = list_GetCellByIndex(loja->bravos, 0);
    
    while(c != NULL) {
        if (strcmp(cell_GetType(c), "gato") == 0){
            receita += 35;
        } else {
            receita += 45;
        }

        c = cell_GetNext(c);
    }

    return receita;
}


/* Libera toda a memória alocada
* inputs: referencia para a loja
* output: não tem
* pre-condicao: loja alocada
* pos-condicao: Toda a memória liberada, a não ser gatos e cachorros, que são responsabilidade do cliente. */
void liberaBanhoTosa(BanhoTosa* loja) {
    if (loja == NULL)
        return;
    list_Free(loja->bravos);
    list_Free(loja->mansos);
    free(loja->nome);
    free(loja);
}