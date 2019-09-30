#include <math.h>
#include <stdbool.h>
#include <stdio.h>

float paraMetrosPorSegundo(float v) {
    return v/3.6;
}

float areaCirculo(float raio) {
    return M_PI * pow(raio, 2);
}

int ehPar(int n) {
    return n % 2 == 0;
}

int ehDivisivelPor3ou5(int n) {
    bool divisivelPor3 = n % 3 == 0;
    bool divisivelPor5 = n % 5 == 0;
    
    if (divisivelPor3 != divisivelPor5)
        return 1;
    else
        return 0;
}

float pesoIdeal(float h, char sexo) {
    if(sexo == 'M')
        return (62.1 * h) - 44.7;
    else if (sexo == 'F')
        return (62.1 * h) - 44.7;
    else {
        printf("Selecione M ou F como sexo");
        return 0;
    }
}

int somaImpares(int n) {
    if(n <= 0)
        return 0;

    if(ehPar(n))
        n--;

    return n + somaImpares(n - 2);
}

double fatorial(int n) {
    if(n == 1)
        return 1;

    return n * fatorial(n - 1);
}

int somaNumerosDiv3ou5(int n) {
    int numeroParaAdicionar;
    
    if(ehDivisivelPor3ou5(n))
        numeroParaAdicionar = n;
    else
        numeroParaAdicionar = 0;

    return numeroParaAdicionar + somaNumerosDiv3ou5(n - 1);
}

float calculaMedia(int x, int y, int z, int operacao) {
    switch operacao {
        case 1: 
            return cbrt(x * y * z);
        case 2: 
            return (x + 2 * y + 3 * z ) / 6;
        case 3: 
            return 3 / (1/x + 1/y + 1/z);
        case 4: 
            return (x + y + z) / 3;
    }
}

int numeroDivisores(int n) {
    int numeroDivisores = 0, possivelDivisor = n;
    
    while(possivelDivisor) {
        if(n % possivelDivisor == 0)
            numeroDivisores++;
    }

    return numeroDivisores;
}

int enesimoFibonacci(int n) {
    
    return 
}