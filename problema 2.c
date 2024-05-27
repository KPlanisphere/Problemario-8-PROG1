//2.Cambiar todas las ocurrencias de una frase

//librerias
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>


//funcion
int buscarReemplazar(char fra[],char pal[],char pal2[]){
    char* cadena;
    int i,cont=0;
    //Aparicion de la palabra
    for(i=0;fra[i]!='\0';i++) {
        if (strstr(&fra[i],pal)==&fra[i]){
            cont++;
            i+=strlen(pal)-1;
        }
    }
    printf("\n  %c",195);
    for (i = 0; i < 70; i++){
        printf("%c",196);
    }
    printf("%c\n",180);
    printf("\n%c N%cmero de reemplazos ulitizados: %d\n",219,163,cont);
    //Cadena nueva con tamano adaptable
    cadena=(char*)malloc(i+cont*(strlen(pal2)-strlen(pal))+1);
    i=0;
    while (*fra){
        //Comparacion
        if (strstr(fra,pal)==fra){
            strcpy(&cadena[i], pal2);
            i+=strlen(pal2);
            fra+=strlen(pal);
        }
        else
            cadena[i++]=*fra++;
    }
    cadena[i]='\0';

    printf("\n%c Esta es la frase resultante: %s\n",219,cadena);

    return 0;
}

//Principal
int main(){
    char fra[500];
    char vieja[100];
    char nueva[100];
    printf ("\t\t%c\t\t\t          %c\n",201,187);
    printf ("\t\t%c Cambia ocurrencias en una frase %c",186,186);
    printf ("\n\t\t%c\t\t\t          %c\n",200,188);
    printf("\n%c Ingrese una frase: ",219);
    gets(fra);
    printf("\n%c De su frase ingresada,%cqu%c palabra le gustar%ca modificar?: ",219,168,130,161);
    gets(vieja);
    printf("\n%c Correcto,%cpor cu%cl palabra va a sustituir la anterior?: ",219,168,160);
    gets(nueva);    
    buscarReemplazar(fra, vieja, nueva);
	getch();
    return 0;
}
