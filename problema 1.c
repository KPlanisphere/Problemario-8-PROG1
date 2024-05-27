#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void delimitadores(char []);

int main(){

    char cadena[100];

    printf("Escriba una frase: ");
    gets(cadena);

    delimitadores(cadena);

    system("pause");
    return 0;
}

void delimitadores(char cadena[]){
    int i,n;
    char delimitador[] = " ";
    char *palabras = strtok(cadena, delimitador);
    for( i = 0; palabras != NULL; i++){
        printf("Palabra %d: %s\n",i, palabras);
        n = strlen(palabras);         
        palabras = strtok(NULL, delimitador);
        printf("Su tama%co es: %d\n\n", 164, n);
    }
}
