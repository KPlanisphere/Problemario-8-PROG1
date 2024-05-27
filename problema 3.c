//Jesús Huerta Aguilar, Javier de La Luz Ruiz, Ernesto Flores Cesareo
//Programación I - "Programa: Ahorcado"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//PROTOTIPOS
void castig(char []);
void mayus(char *);
void notas(char []);
void life(int);
void xword(int,int,char [],char []);
void duro();
void death(int *,int,char [][20],char []);
void win(int *,int , char []);
void start(char []);
void cont(char *);
void horca(int);
//PRINCIPAL
int main(){
    char des,nombre[50];
    int tamnom;
    do{
        castig(nombre);
        start(nombre);
        cont(&des);
    } while (des == 's' || des == 'S');
    getch();
    return 0;
}
//CONVERTIR A MAYUSCULAS
void mayus(char *word){
    int i;
    if (*word >= 'a' && *word <= 'z'){
        *word -= 32;
    }
}
//CASTIGADO
void castig(char nombre[]){
    char op,aux[50],aux2[]={"ALGUIEN"};
    int error;
    do{
        error = 0;
        printf("%cDesea asignar un nombre al castigado? [S/N] >> ",168);
        scanf("%c",&op);
        fflush(stdin);
        if (op == 's' || op == 'S'){
            printf("\nIngrese el nombre: ");
            fgets(aux,50,stdin);
            aux[strlen(aux)-1]='\0';
            strcpy(nombre,aux);
            if (strcmp(nombre,"LESKY") == 0){
                duro();
            }
        }
        else{
            if (op == 'n' || op == 'N'){
                strcpy(nombre,aux2);
            }
            else{
                printf("\n[!] ERROR: Ingresa una opci%cn valida [!]",162);
                error = 1;
                system("cls");
            }
        }
    } while (error == 1);
    system("cls");
}
//NOTAS
void notas(char nombre[]){
    int i;
    printf("\n\t\tPROGRAMACION I\t\t\t - \t\t\tEQUIPO 8");
    printf(R"EOF(
         ________  ___  ___  ________  ________  ________  ________  ________  ________     
        |\   __  \|\  \|\  \|\   __  \|\   __  \|\   ____\|\   __  \|\   ___ \|\   __  \ %c        
        \ \  \|\  \ \  \\\  \ \  \|\  \ \  \|\  \ \  \___|\ \  \|\  \ \  \_|\ \ \  \|\  \   
         \ \   __  \ \   __  \ \  \\\  \ \   _  _\ \  \    \ \   __  \ \  \ \\ \ \  \\\  \  
          \ \  \ \  \ \  \ \  \ \  \\\  \ \  \\  \\ \  \____\ \  \ \  \ \  \_\\ \ \  \\\  \ 
           \ \__\ \__\ \__\ \__\ \_______\ \__\\ _\\ \_______\ \__\ \__\ \_______\ \_______\
            \|__|\|__|\|__|\|__|\|_______|\|__|\|__|\|_______|\|__|\|__|\|_______|\|_______|
    )EOF",169);
    printf("\n\t\t\t\t  SALVA LA VIDA DE %s",nombre);
}
//CONTINUAR?
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
                printf("\n\n\t\t\t\tGRACIAS POR USAR NUESTROS SERVICIOS");
                printf("\n\n\t\t\t\t   EQUIPO 8\t-\tBUAP\n\n");
                printf("\t\t\t\t\t    POWERED BY:\n");
                printf(R"EOF(
                    /$$$$$$$$ /$$$$$$   /$$$$$$  /$$$$$$$  /$$        /$$$$$$ 
                    | $$_____//$$__  $$ /$$__  $$| $$__  $$| $$       /$$__  $$
                    | $$     | $$  \__/| $$  \__/| $$  \ $$| $$      | $$  \__/
                    | $$$$$  | $$      | $$      | $$  | $$| $$      | $$ /$$$$
                    | $$__/  | $$      | $$      | $$  | $$| $$      | $$|_  $$
                    | $$     | $$    $$| $$    $$| $$  | $$| $$      | $$  \ $$
                    | $$     |  $$$$$$/|  $$$$$$/| $$$$$$$/| $$$$$$$$|  $$$$$$/
                    |__/      \______/  \______/ |_______/ |________/ \______/ 
                )EOF");
            }
            else{
                printf("\n\t[!] ERROR: Ingresa una opci%cn valida [!]\n\n\t",162);
                error = 1;
            }
        }
    } while (error == 1);
}
//VIDAS
void life(int try){
    int i;
    printf("\n\n\tVIDAS [%d] ",7-try);
    for (i = 0; i < 7-try; i++){
        printf("%c",03);
        printf(" ");
    } 
}
//PALABRA DESCIFRADA
void xword(int tam,int try,char cens[],char nombre[]){
    int i;     
    printf("\t\t\t\t\t");
    for (i = 0; i < try+1; i++){//ESPACIOS
        printf("  ");
    }
    printf("%c ",16);
    for (i = 0; i < tam; i++){
        printf("%c",cens[i]);
        printf(" ");
    }
    //AVISO ULTIMO INTENTO
    printf("%c",17);
    if (try == 6){
        printf("\n\n\t     [!] ES TU ULTIMO INTENTO, LA VIDA DE %s ESTA EN TUS MANOS [!]",nombre);     
    }
}
//MUERTE
void death(int *try,int act,char word[][20],char nombre[]){
    if (*try == 7){
        printf("\n\n\n\t\t\t\t   [!] %s HA MUERTO [!]",nombre);
        printf("\n\t\t\t\tLA RESPUESTA ERA: %s",word[act]);
        printf("\n\n\n\t");
        *try = 8;
    }
}
//VICTORIA
void win(int *try,int tam, char cens[]){
    int i,x;
    x = 0;
    for (i = 0; i <tam; i++){
        if (cens[i] == 'X'){
            x++;
        }
    }
    if (x == 0){
        printf("\n\n\n\t\t\t%c%c %cFELICIDADES! USTED PUDO ADIVINAR MI PALABRA %c%c",205,205,173,205,205);
        printf("\n\n\t\t\t\t   ");
        *try = 8;
    }
}
//INICIO
void start(char nombre[]){
    char word[10][20] = {"AMLO","LUIS","PROGRAMADORESE3","MEMELAS","MOMERO","ESTRADA","WATSAP2","FCCDLG","PAPU","SDLG"};
    int act,tam,i,correct,try=0;
    char letra,x;
    srand(time(NULL));
    act = rand() % 10;
    tam = strlen(word[act]);
    char cens[tam];
    //COLOCAR X
    for (i = 0; i < tam; i++){
        cens[i] = 'X';
    }
    do{
        system("cls");
        correct = 0;
        notas(nombre);
        //DIBUJO
        horca(try);
        printf("\n\n");
        //Separador
        printf("  ");
        for (i = 0; i < 95; i++){
            printf("%c",205);
        }
        //VIDAS
        life(try);
        //Palabra desifrada
        xword(tam,try,cens,nombre);
        //MUERTE
        death(&try,act,word,nombre);
        //VICTORIA
        win(&try,tam,cens);
        //ENTRADA DE LETRAS
        if (try < 8){
            printf("\n\n\tINGRESE UNA LETRA: ");
            scanf(" %c",&letra);
            mayus(&letra);
            for (i = 0; i < tam; i++){
                if (letra == word[act][i]){
                    cens[i] = letra;
                    correct++;
                }
            }
            if (correct == 0){
                try++;
            }
        }
    } while (try < 8);
}
//DIBUJO HORCA
void horca(int try){
	switch(try){
		case 0:
			printf("\n\t\t\t\t\t     _______\n\t\t\t\t\t    |       |\n\t\t\t\t\t    |\n\t\t\t\t\t    |\n\t\t\t\t\t    |\n\t\t\t\t\t    |\n\t\t\t\t\t    |\n\t\t\t\t\t ----------");
			break;
		case 1:
			printf("\n\t\t\t\t\t     _______\n\t\t\t\t\t    |       |\n\t\t\t\t\t    |       0\n\t\t\t\t\t    |\n\t\t\t\t\t    |\n\t\t\t\t\t    |\n\t\t\t\t\t    |\n\t\t\t\t\t ----------");
			break;
		case 2:
			printf("\n\t\t\t\t\t     _______\n\t\t\t\t\t    |       |\n\t\t\t\t\t    |       0\n\t\t\t\t\t    |       |\n\t\t\t\t\t    |\n\t\t\t\t\t    |\n\t\t\t\t\t    |\n\t\t\t\t\t ----------");
			break;
		case 3:
			printf("\n\t\t\t\t\t     _______\n\t\t\t\t\t    |       |\n\t\t\t\t\t    |       0\n\t\t\t\t\t    |      /|\n\t\t\t\t\t    |\n\t\t\t\t\t    |\n\t\t\t\t\t    |\n\t\t\t\t\t ----------");
			break;
		case 4:
			printf("\n\t\t\t\t\t     _______\n\t\t\t\t\t    |       |\n\t\t\t\t\t    |       0\n\t\t\t\t\t    |      /|");
			printf("\\");
			printf("\n\t\t\t\t\t");
			printf("    |\n\t\t\t\t\t    |\n\t\t\t\t\t    |\n\t\t\t\t\t ----------");
			break;
        case 5:
            printf("\n\t\t\t\t\t     _______\n\t\t\t\t\t    |       |\n\t\t\t\t\t    |       0\n\t\t\t\t\t    |      /|");
			printf("\\");
			printf("\n\t\t\t\t\t");
			printf("    |       |\n\t\t\t\t\t    |\n\t\t\t\t\t    |\n\t\t\t\t\t ----------");
			break;
		case 6:
			printf("\n\t\t\t\t\t     _______\n\t\t\t\t\t    |       |\n\t\t\t\t\t    |       0\n\t\t\t\t\t    |      /|");
			printf("\\");
			printf("\n\t\t\t\t\t");
            printf("    |       |\n\t\t\t\t\t    |");
			printf("      /\n\t\t\t\t\t    |\n\t\t\t\t\t ----------");
			break;
		case 7:
			printf("\n\t\t\t\t\t     _______\n\t\t\t\t\t    |       |\n\t\t\t\t\t    |       0\n\t\t\t\t\t    |      /|");
			printf("\\");
			printf("\n\t\t\t\t\t");
			printf("    |       |");
            printf("\n\t\t\t\t\t");
			printf("    |      / ");
			printf("\\");
			printf("\n\t\t\t\t\t");
			printf("    |\n\t\t\t\t\t ----------");
			break;
	}
}






























































































































































































































































//EASTER EGG
void duro(){
    system("cls");
    printf(R"EOF(
llllllllllllllllllllllc:;,,''''',,;:ccllllllllllllllllllllll
llllllllllllllllllc;'..             ...,:cllllllllllllllllll
llllllllllllllll:'.                      .,:llllllllllllllll
llllllllllllll;.                           .':llllllllllllll
llllllllllll:.                                .:llllllllllll
llllllllll:.                  ............     .'cllllllllol
lllllllll:.      ....',,,''..,;:ccccccc:;,'...   .clllllllol
llllllll:.     ...',;;::ccccclloooooooolcc:;,'..  .collllllo
lllllllc.    ....',;;:ccllllooooddxxxddollc:;;,..  ,lolllloo
lllllll;   .....',,;:ccllllooooodxxxxddollc::;;,.  .:olllool
lllllll.   .....',,;;:cclloddddddxxxxddollc:::;,.   'lllooll
llllllc.   ....'',;;:clodddxxxxxxxxkkkxdollc::;;'.  .coloool
llllll:.  .....',;;:cloddxkkkkkkkkkkkkkdoc:;;,,;,.. .:olloll
llllllc.  ............';ldxxkkkkkkdl:;''........,,. .colllll
llllllc. ...    ......',;coodxxxxdoc:::::cc:;,'..,' .lolllll
llllllc. ..  ..,:llooollc::codxxdoooooodxxxddol:,,,..:llllll
llllll:......',,;:cooooooc;,cdkxdooooc:::c::c:::::,..':lllll
llllll:.............';c:ll;':dxxdoodc;,.......',::;'',clllll
lllllll'.........'',:loloc,,:oddoolooc:::ccc:;;:cc;'':llllll
lllllll,...',,;;:cloooool;,,:looolloddddoooooollcc:,,:llllll
lllllll,...',:loddddddooc,,,;cooollloxkkxxddddddolc,,cllllll
lllllll;...';:lodddxxxoc;''';cllolccoxkkkxxxxxxxdoc;:lolllll
lllllll:. ..,:codxkkkko;...,:looooc::lxxkkkOOOkxdoc::lolllll
lllllllc. ..,:loxkOOkd:..'':lodxkxocccoddxkOOOkxdoc;:lllllll
llllllll,...,cldxkkkxl,.,;,:ldxxkxoc:ldxoodxkxxdol:;collllll
llllllll:. .':cloddocc:,,''';:cclllccoddolloddoolc;:lollllll
lllllllll, ..';:c:;,,,,,,',;:ccllooolllolc::lllcc;;cllllllll
lllllllllc' ..,::,''..',,,,;cccccllcccccc:::clcc:;:lllllllll
llllllllllc...';cc:,'.......',;;;;,,,,,:c:cllc::;:llllllllll
lllllllllll:...';c:;''.....,;:::::;,,,:lc:cc:;;;clllllllllll
llllc:;,''...  ...'''''''.',;clcc:;;:clc:;;;,,,:llllllllllll
;,'...    ..      ...'''''',,,;;::ccccc::;;,,,,,,,;:clllllll
       ....   ..    .',,,,,,,;;;;:c:::::;,',;;,''......';:cc
       ....   ....   .',,,;::cclllc::::,',;;:;,'',,,,.    ..
       ....   ......  ..',,,;:::ccc:;;'';::::;;,,;;;:;.     
       ....    ....... ......',,,,''',;:ccc::;;,;:ccl:.     
        ....    ................'',;:cccccc::::::cllo;.     
         ..................'',,;;:ccclllccc:::ccclooc.      
          .',''.......''''',,,;;;:ccllllccccccclooo:.       
           .,::;,'..',,;,,,;;;:::ccllllccccclllodl,         
             .;llc:;;:ccc:::::::cclllllclllooooc,.          
               .';:ccloooollllllloooolloooooc,.             
                   ..',:cclllooooooollc:;,.. .............  
                           ..........        ............. 

    )EOF");
    getch();
}