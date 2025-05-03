#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define PI 3.14159

/**
 * @brief função que calcula a area e o volume de uma esfera.
 * @param r raio da esfera.
 * @param area ponteiro para a variável float que armazenará a área de superfície da esfera.
 * @param volume ponteiro para a variável float que armazenará o volume da esfera.
*/
void calc_esfera(float r, float* area, float* volume);

/**
 * @brief função que calcula as raízes de uma equação do segundo grau. (ax² + bx + c = 0)
 * @param a o coeficiente 'a' da equação.
 * @param b o coeficiente 'b' da equação.
 * @param c o coeficiente 'c' da equação.
 * @param x1 ponteiro para a variável float que arazenará uma das raízes da equação.
 * @param x2 ponteiro para a variável float que arazenará a outra raíz da equação.
 * @return a quantidade de raízes que a equação possui.
 */
int raizes(float a, float b, float c, float* x1, float* x2);

/**
 * @brief função que retorna a quantidade de números pares no vetor fornecido.
 * @param n número de elementos no vetor.
 * @param vet o vetor em questão (ponteiro).
 * @return a quantidade de números pares no vetor.
 */
int pares(int n, int* vet);

/**
 * @brief função que inverte a ordem dos elementos em um vetor.
 * @param n quantidade de elementos no vetor.
 * @param vet o vetor a ser invertido (ponteiro).
 */
void inverte(int n, int* vet);

/**
 * @brief função que calcula o valor de um polinomio.
 * @param poli vetor com os coeficientes do polinomio.
 * @param grau o grau do polinomio.
 * @param x o valor da variável.
 * @return o valor do polinomio (double).
 */
double avalia(double* poli, int grau, double x);

/**
 * @brief função de compara que é usada em conjunto com a qsort na funcao inverte2.
 * @param n1 ponteiro para o primeiro elemento (que um ponteiro de int, entao trabalhamos com int**);
 * @param n2 ponteiro para o segundo elemento.
 * @return < 0 se n1 < n2, > 0 se n1 > n2 e 0 se n1 = n2.
 */
int compara(const void* n1, const void* n2);

/**
 * @brief função que cria um vetor de ponteiros ordenado com referencias para os elementos do vetor original;
 * @param n quantidade de elementos no vetor.
 * @param vet o vetor original.
 * @return o vetor de ponteiros ordenado.
 */
int** inverte2(int n, int* vet);

int main() {
    int opt = 0;

    while (1) {
        printf("Digite o numero correspondente a função que você deseja testar:\n");
        printf("[1] - calc_esfera;\n");
        printf("[2] - raizes;\n");
        printf("[3] - pares;\n");
        printf("[4] - inverte;\n");
        printf("[5] - avalia;\n");
        printf("[6] - inverte2;\n");
        printf("[0] - SAIR DO PROGRAMA\n");
        printf("Opcao escolhida: ");

        scanf("%d%*c", &opt);
        printf("\n");

        if (opt == 0) {
            break;
        } else if (opt == 1) {
            float r = 0, area = 0, volume = 0;

            printf("Digite o raio da sua esfera: ");
            scanf("%f%*c", &r);

            printf("\n");

            calc_esfera(r, &area, &volume);

            printf("Volume: %.2f\n", volume);
            printf("Area: %.2f\n", area);
        } else if (opt == 2) {
            float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

            printf("Digite os coeficientes:\n");
            printf("a = ");
            scanf("%f%*c", &a);
            printf("\nb = ");
            scanf("%f%*c", &b);
            printf("\nc = ");
            scanf("%f%*c", &c);
            printf("\n");

            if (raizes(a, b, c, &x1, &x2)) {
                printf("X1 = %.2f\n", x1);
                printf("X2 = %.2f\n", x2);
            } else {
                printf("A equacao nao possui raizes reais.\n");
            }
        } else if (opt == 3) {
            int n;
            int* vet;
            printf("Digite o numero de elementos no vetor: ");
            scanf("%d%*c", &n);
            printf("\n");

            vet = (int*)malloc(sizeof(int) * n);

            printf("Digite os elementos do vetor:\n");

            for (int i = 0; i < n; i++)
                scanf("%d%*c", &vet[i]);
            
            printf("Quantidade de numeros pares no vetor: %d\n", pares(n, vet));

            free(vet);
        } else if (opt == 4) {
            int n;
            int* vet;
            printf("Digite o numero de elementos no vetor: ");
            scanf("%d%*c", &n);
            printf("\n");

            vet = (int*)malloc(sizeof(int) * n);

            printf("Digite os elementos do vetor:\n");

            for (int i = 0; i < n; i++)
                scanf("%d%*c", &vet[i]);
            
            inverte(n, vet);

            printf("Vetor invertido:\n");

            for (int i = 0; i < n; i++) 
                printf("%d ", vet[i]);
            
            printf("\n");
            
            free(vet);
        } else if (opt == 5) {
            int grau;
            double x, *poli;
            printf("Digite o valor de x: ");
            scanf("%lf%*c", &x);
            printf("Digite o grau do polinomio: ");
            scanf("%d%*c", &grau);
            printf("\n");

            poli = (double*)malloc(sizeof(double) * (grau + 1));

            printf("Digite os coeficientes do polinomio (do menor grau para o maior):\n");

            for (int i = 0; i <= grau; i++)
                scanf("%lf%*c", &poli[i]);
            
            printf("Resultado: %.2lf\n", avalia(poli, grau, x));
        } else if (opt == 6) {
            int n;
            int* vet;
            printf("Digite o numero de elementos no vetor: ");
            scanf("%d%*c", &n);
            printf("\n");

            vet = (int*)malloc(sizeof(int) * n);

            printf("Digite os elementos do vetor:\n");

            for (int i = 0; i < n; i++)
                scanf("%d%*c", &vet[i]);
            
            int** vet2 = inverte2(n, vet);

            printf("Vetor de referencias ordenado:\n");

            for (int i = 0; i < n; i++) 
                printf("%d ", *vet2[i]);
            
            printf("\n");
            
            free(vet);
            free(vet2);
        }
    }

    
    return 0;
}

void calc_esfera(float r, float* area, float* volume) {
    *area = 4 * PI * pow(r, 2);
    *volume = ((float)4/(float)3) * PI * pow(r, 3);
}

int raizes(float a, float b, float c, float* x1, float* x2) {
    float delta = pow(b, 2) - (4 * a * c);

    if (delta < 0) return 0; //Não possui raízes reais, x1 e x2 permanecem inalterados.

    *x1 = (-b + sqrt(delta))/(2 * a);
    *x2 = (-b - sqrt(delta))/(2 * a);

    if (delta > 0) return 2;
    return 1;
}

int pares(int n, int* vet) {
    int nPares = 0;

    for (int i = 0; i < n; i++) {
        if (vet[i] % 2 == 0) //O resto da divisão por 2 é zero <=> é par.
            nPares++;
    }

    return nPares;
}

void inverte(int n, int* vet) {
    for (int i = 0; i < n / 2; i++) {
        //Troca de posição o primeiro com o ultimo e assim por diante até chegar no "meio";
        int aux = vet[i];
        vet[i] = vet[n - i - 1];
        vet[n - i - 1] = aux;
    }
}

double avalia(double* poli, int grau, double x) {
    double result = 0;

    for (int i = 0; i <= grau; i++)
        result += poli[i] * pow(x, i);

    return result;
}

int compara(const void* n1, const void* n2) {
    return (**(int **)n1 - **(int **)n2);
}

int** inverte2(int n, int* vet) {
    int** result = (int**)malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++)
        result[i] = &vet[i];
    
    qsort(result, n, sizeof(int*), compara);

    return result;
}