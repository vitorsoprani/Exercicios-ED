#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printVet(int* vet, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void swap(int* i, int* j) {
    *i = *i ^ *j;
    *j = *i ^ *j;
    *i = *i ^ *j;
}

void bubbleSort(int* vet, size_t tam) {
    for (int i = 0; i < tam - 1; i++)
        for (int j = 0; j < tam - i - 1; j++)
            if (vet[j] > vet[j + 1])
                swap(&vet[j], &vet[j+1]);
}

int main(int argc, char** argv) {
    clock_t t;

    if (argc < 2) {
        fprintf( stderr, "Sem argumentos\n");
        return 1;
    }

    int tam = atoi(argv[1]);
    if (tam == 0) {
        fprintf(stderr, "Argumento invalido\n");
        return 1;    
    }

    int vet[tam];

    for (int i = 0; i < tam; i++) {
        vet[i] = rand() % tam;
    }

    if (argc > 2) printVet(vet, tam);

    t = clock();
    bubbleSort(vet, tam);
    t = clock() - t;
    
    if (argc > 2) printVet(vet, tam);

    printf("o bubble sort levou: %lfs\n", ((double)t)/CLOCKS_PER_SEC);

    return 0;
}
