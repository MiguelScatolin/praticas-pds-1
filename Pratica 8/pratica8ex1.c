#include <stdio.h>
#include <stdlib.h>

int randomNumberBetween(int min,int max) {
    return min + ( rand() % max );
}

void leValor(int *valor, int min, int max) {
    do {
        printf("Digite um valor entre %i e %i: ", min, max);
        scanf("%i", valor);
    } while(*valor < min || *valor > max);
}

void leValores(int *m, int *n, int *k) {
    leValor(m, 1, 100);
    leValor(n, 1, 100);
    leValor(k, 1, 100);
}

void preencheAleatoriamente(int matriz[][100], int m, int n, int k) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            matriz[i][j] = randomNumberBetween(1, k);
        }
    }
}

void imprimeMatriz(int matriz[][100], int m, int n) {
    printf("\n  Matriz %ix%i \n", m, n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%3i", matriz[i][j]);
        }
        printf("\n");
    }
}

void substituiSequenciaHorizontalPorZero(int matriz[][100], int m, int n, int sequencia) {
    for(int i = 0; i < sequencia; i++) {
        matriz[m][n - i] = 0;
    }
}

void substituiSequenciaVerticalPorZero(int matriz[][100], int m, int n, int sequencia) {
    for(int i = 0; i < sequencia; i++) {
        matriz[m - i][n] = 0;
    }
}

int procuraSequencias(int matriz[][100], int m, int n) {
    int sequencia = 0, numSequencias;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matriz[i][j] == matriz[i][j+1]) {
                if(sequencia == 0)
                    sequencia = 2;
                else
                    sequencia++;
            } else {
                if(sequencia >= 3) {
                    substituiSequenciaHorizontalPorZero(matriz, i, j, sequencia);
                    numSequencias++;
                    sequencia = 0;
                }else
                    sequencia = 0;
            }
        }
        sequencia = 0;
    }

    imprimeMatriz(matriz, m, n);

    sequencia = 0;

    for(int j = 0; j < n; j++) {
        for(int i = 0; i < m; i++) {
            if(matriz[i][j] == matriz[i+1][j]) {
                if(sequencia == 0)
                    sequencia = 2;
                else
                    sequencia++;
            } else {
                if(sequencia >= 3) {
                    substituiSequenciaVerticalPorZero(matriz, i, j, sequencia);
                    numSequencias++;
                    sequencia = 0;
                } else
                    sequencia = 0;
            }
        }
        sequencia = 0;
    }

    return numSequencias;
}

int contaZerosDaMatriz(int matriz[][100], int m, int n) {
    int numeroZeros = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matriz[i][j] == 0)
                numeroZeros++;
        }
    }
    return numeroZeros;
}

void sobeZeros(int matriz[][100], int m, int n) {
    for(int j = 0; j < n; j++) {
        for(int i = m; i > 0; i--) {
            if(matriz[i][j] == 0 && matriz[i-1][j] != 0) {
                matriz[i][j] = matriz[i-1][j];
                matriz[i-1][j] = 0;
                i = m;
            }
        }
    }
}

void main()
{
    int m, n, k, zerosMatriz = 0, sequenciasEncontradas = 0;

    leValores(&m, &n, &k);

    int matriz[m][n];

    preencheAleatoriamente(matriz, m, n, k);

    imprimeMatriz(matriz, m, n);

    do {
        sequenciasEncontradas = procuraSequencias(matriz, m, n);
        imprimeMatriz(matriz, m, n);

        zerosMatriz = contaZerosDaMatriz(matriz, m, n);
        printf("\n A matriz possui %i zeros", zerosMatriz);

        sobeZeros(matriz, m, n);
        imprimeMatriz(matriz, m, n);
    } while(sequenciasEncontradas <= 0);
}
