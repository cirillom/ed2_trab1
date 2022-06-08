#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ctrlF(FILE* texto, FILE* trechos,FILE* saida)
{
    char textoString[2000];
    fgets(textoString,sizeof(textoString),texto);


    char trechoString[200];

    while(fgets(trechoString,sizeof(trechoString),trechos)){
        
        trechoString[strlen(trechoString)-1] = '\0';

        int i = 0;

        while(textoString[i] != '\0'){
            int j = 0;
            while((trechoString[j]!= '\0') && (textoString[i+j] == trechoString[j])){
                j+=1;
            }
            if(trechoString[j] == '\0'){
                fprintf(saida,"%d, %d\n",i,i+j - 1);
                break;
            }
            i+=1;
        }
    }
    rewind(trechos);
}