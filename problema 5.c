//Jesús Huerta Aguilar, Javier de La Luz Ruiz, Ernesto Flores Cesareo
//Programación I - "Programa: mayusculas / minusculas"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//PROTOTIPOS
void des(char[],int);
void minus(char[],int);
void mayus(char[],int);
void cont(char *);
//PRINCIPAL
int main(){
    int tam,aux;
    char op,cad[1000];
    do{
        printf("\nIngrese una frase: ");
        scanf("%d",aux); //??
        /*while (fgets(cad,sizeof(cad),stdin ) != NULL && cad[0] != '\n' ){
            cad[strcspn(cad, "\n" ) ] = '\0';
            puts(cad);
        }*/
        fgets(cad,sizeof(cad),stdin);
        tam = strlen(cad);
        des(cad,tam);
        cont(&op);
    } while (op == 'S' || op == 's');
    getch();
    return 0;
}
//DESICION
void des(char cad[],int tam){
    int des,error;
    do{
    printf("\n%cQue desea hacer?\n",168);
    printf("\n\t[1] - Mayusculas a Minusculas");
    printf("\n\t[2] - Minusculas a Mayusculas");
    printf("\n\n///// ");
    scanf("%d",&des);
    switch (des){
    case 1:
        minus(cad,tam);
        break;
    case 2:
        mayus(cad,tam);
        break;
    default:
        printf("\n\n[!] ERROR: Ingresa una opcin valida [!]");
        error = 1;
        break;
    }
    } while (error == 1);
    printf("\n\t");
    puts(cad);
}
//CONVERTIR A MINUSCULAS
void minus(char cad[],int tam){
    int i;
    for (i = 0; i < tam; i++){
        if (cad[i] >= 'A' && cad[i] <= 'Z'){
            cad[i] += 32;
        } 
    }
}
//CONVERTIR A MAYUSCULAS
void mayus(char cad[],int tam){
    int i;
    for (i = 0; i < tam; i++){
        if (cad[i] >= 'a' && cad[i] <= 'z'){
            cad[i] -= 32;
        } 
    }
}
//CONTINUAR
void cont(char *op){
    int error;
    do{
        error = 0;
        printf("%cDesea continuar? [S/N] >> ",168);
        scanf("%s",op);
        if (*op == 's' || *op == 'S'){
            system("cls");
        }
        else{
            if (*op == 'n' || *op == 'N'){
                system("cls");
                printf("\n\n\tGRACIAS POR USAR NUESTROS SERVICIOS");
                printf("\n\n\t   Equipo 8\t-\tBUAP");
            }
            else{
                printf("\n[!] ERROR: Ingresa una opci%cn valida [!]",162);
                error = 1;
            }
        }
    } while (error == 1);
}