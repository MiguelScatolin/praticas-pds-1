#include <stdio.h>
#include "prova.h"

void main() {
    int a, b;
    leIntervalo(&a, &b);

    int c, n = a + 1, max_n, max_c = 0;
    while(n < b) {
        c = collatz(n);

        if(c > max_c) {
            max_c = c;
            max_n = n;
        }
        n++;
    }
    printf("\nNumero com a maior sequencia de Collatz:");
    printf(" %d (%d passos)", max_n, max_c);
}