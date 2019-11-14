#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_TAM 5

 void main() {
     int currentBufferCount = 0, totalCharacterCount = 0;
    char buffer[BUFFER_TAM], currentCharacter;
    char *texto, *textoAux;

    do {
        currentCharacter = getchar();

        if(currentCharacter == '\r') {
            printf("\n");
            currentCharacter = '\n';
        }

        buffer[currentBufferCount] = currentCharacter;
        currentBufferCount++;
        totalCharacterCount++;

        if(currentBufferCount == 5 || currentCharacter == '#') {
            textoAux = (char *) malloc(totalCharacterCount * sizeof(char));
            strcpy(textoAux, texto);
            strcat(textoAux, buffer);
            free(texto);
            texto = textoAux;
        }
    } while(currentCharacter == '#');

    texto[totalCharacterCount-1] = '\0';

    printf("%s", textoAux);

    free(texto);

 }
