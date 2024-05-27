#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int esanagrama (char *palb1, char *palb2)
{
    int l, k, a=0, b=0, i, j, aciertos=0, palabra1, palabra2;
    
    palabra1 = strlen(palb1);
    palabra2 = strlen(palb2);

    //Quitar espacios
    //Determinar espacio en la primera palabra
    while (palb1[a] != '\0')
    {
        if (palb1[a] == ' ')
        {
            for (k = a; k < palabra1; k++)
            {
                palb1[k]=palb1[k+1];
            }
            palabra1--;
        }
        a++;
    }
        //Determinar espacio en la segunda palbra
        while (palb2[b] != '\0')
        {
            if (palb2[b] == ' ')
            {
                for (l = b; l < palabra2; l++)
                {
                    palb2[l]=palb2[l+1];
                }
                palabra2--;
            }
            b++;
        }
        
    //Determinar anagrama
    if (palabra1 != palabra2)
    {
        return 1;
    }else
    {
        for (i=0; i<palabra1; i++)
        {
            for (j=0; j<palabra2; j++)
            {
                if (palb1[i] == palb2[j])
                {
                    palb2[j] = '#';
                    aciertos++;
                }
            }
        }
    }
    if (aciertos == palabra2)
    {
        return 0;
    }else
    {
        return 1;
    }
}

int main(){

    int anagrama, palabra1, palabra2, k, a=0;
    char palb1[100], palb2[100];

    printf("\n Escriba una palabra:\n");
    gets(palb1);
    printf("\n Escriba otra palabra para identificar si son anagramas: \n");
    gets(palb2);

    anagrama = esanagrama(palb1,palb2);

    if (anagrama == 0)
    {
        printf("\n Las 2 palabras son anagramas");
    }else
    {
       printf("\n Las 2 palabras NO son anagramas");
    }
    
    printf("\n\n");
    system("pause");
    return 0;
}