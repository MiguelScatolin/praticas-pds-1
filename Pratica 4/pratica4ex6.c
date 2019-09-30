#include <stdio.h>
#include "pratica4.h"

void main () {
    float altura, peso;
    char sexo;
    float meta;

    do {
        printf("\nInforme seu peso: ");
        scanf("%f", &peso);
    } while (peso <= 0);

    do  {
        printf("\nInforme sua altura: ");
        scanf("%f", &altura);
    } while (altura <= 0);

    do  {
        printf("\nInforme seu sexo ('F' ou 'M'): ");
        scanf("%c", &sexo);
    } while (sexo != 'M' && sexo != 'F');

    meta = pesoIdeal(altura, sexo) - peso;
    if(meta > 0)
        printf("Voce deve ganhar %f quilos", meta);
    else
        printf("Voce deve perder %f quilos", meta * -1);

}