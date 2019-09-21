#include <stdio.h>

int hotpo (unsigned int n) {
    if(n % 2 == 0) {
        return n/2;
    } else {
        return n * 3 + 1;
    }
}

int collatz(unsigned int n) {
    int counter = 0;
    while(n != 1) {
        counter++;
        n = hotpo(n);
    }
    return counter;
}

void leIntervalo(int *min, int *max) {
    int minLido, maxLido;
    do {
        printf("\nDigite um valor minimo e um valor maximo\n");
        scanf("%d %d", &minLido, &maxLido);
    } while(minLido <= 0 || maxLido <= 0 || minLido >= maxLido);
    *min = minLido;
    *max = maxLido;
}
