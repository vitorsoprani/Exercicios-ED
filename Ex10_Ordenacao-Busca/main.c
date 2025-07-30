#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int* arr, int size, int elem) {
    int a = 0, b = size - 1;
    
    int half = (a + b)/2;

    while(arr[half] != elem && a <= b) {
        if (elem < arr[half])
            b = half - 1;
        else
            a = half + 1;

        half = (b + a)/2;
    }

    return arr[half] == elem ? half : -1;
}

int linearSearch(int* arr, int size, int elem) {
    for (int i = 0; i < size; i++)
        if (arr[i] == elem) return i;
    return -1;
}

int compareInt(int* a, int* b) {
    return *a - *b;
}

void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* i, int* j) {
    *i = *i ^ *j;
    *j = *i ^ *j;
    *i = *i ^ *j;
}

void bubbleSort(int* arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j+1]);
        }
    }
}

void quickSort(int* arr, int first, int last) {
    //Condicao de parada
    if (last + 1 - first <= 1)
        return;

    //Escolhe o pivo
    int pivot = arr[first];

    //Organiza o array para este pivo
    int a = first + 1, b = last;
    
    do {
        //encontra o primeiro elemento maior que o pivo:
        while(arr[a] <= pivot && a <= last) a++;

        //encontra o ultimo elmento menor ou igual ao pivo:
        while (arr[b] > pivot) b--;

        if (a < b) {
            swap(&arr[a], &arr[b]);
            a++;
            b--;
        }
    } while (a <= b);
    
    //coloca o pivo na posição correta
    arr[first] = arr[b];
    arr[b] = pivot;

    //chama a função para os 2 subarrays gerados a partir do pivo
    
    quickSort(arr, first, b - 1);
    quickSort(arr, b + 1, last);
}

int main(int argc, char** argv) {
    // TRATANDO ERROS NOS ARGUMENTOS
    if (argc < 2) {
        fprintf( stderr, "Sem argumentos\n");
        return 1;
    }

    int size = atoi(argv[1]);
    if (size < 1) {
        fprintf(stderr, "Argumento invalido\n");
        return 1;    
    }

    clock_t t;
    srand(10);

    int arr1[size];
    int arr2[size];
    int arr3[size];
    for (int i = 0; i < size; i++) {
        arr1[i] = arr2[i] = arr3[i] = rand() % size;
    }
    int elem = rand() % size;

    if (argc > 2) printArr(arr1, size);
    
    
    t = clock();
    printf("O elemento %d esta na posicao %d\n", elem, linearSearch(arr1, size, elem));
    t = clock() - t;
    printf("a busca linear (com o vetor desordenado) levou: %lfs\n", ((double)t)/CLOCKS_PER_SEC);
    if (argc > 2) printArr(arr1, size);

    t = clock();
    bubbleSort(arr1, size);
    t = clock() - t;
    printf("o bubble sort levou: %lfs\n", ((double)t)/CLOCKS_PER_SEC);
    if (argc > 2) printArr(arr1, size);

    t = clock();
    quickSort(arr2, 0, size - 1);
    t = clock() - t;
    printf("o quicksort levou: %lfs\n", ((double)t)/CLOCKS_PER_SEC);
    if (argc > 2) printArr(arr2, size);

    t = clock();
    qsort(arr3, size, sizeof(int), compareInt);
    t = clock() - t;
    printf("o qsort (stdlib) levou: %lfs\n", ((double)t)/CLOCKS_PER_SEC);
    if (argc > 2) printArr(arr3, size);

    t = clock();
    printf("O elemento esta na posicao %d\n", binarySearch(arr1, size, elem));
    t = clock() - t;
    printf("a busca binaria levou: %lfs\n", ((double)t)/CLOCKS_PER_SEC);
    if (argc > 2) printArr(arr2, size);

    return 0;
}
