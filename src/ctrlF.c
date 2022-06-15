#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

void ctrlF(char* arq_texto, char* arq_trechos, char* arq_saida){
    FILE* fp_texto = fopen(arq_texto, "r");
    if(fp_texto == NULL) ABORTPROGRAM("%s", arq_texto);

    FILE* fp_trechos = fopen(arq_trechos, "r");
    if(fp_trechos == NULL) ABORTPROGRAM("%s", arq_trechos);

    FILE* fp_saida = fopen(arq_saida, "w");
    if(fp_saida == NULL) ABORTPROGRAM("%s", arq_saida);


    char textoString[2000000];
    fgets(textoString,sizeof(textoString),fp_texto);

    char trechoString[2000000];
    while(fgets(trechoString,sizeof(trechoString),fp_trechos)){
        
        trechoString[strlen(trechoString)-1] = '\0';

        int i = 0;

        while(textoString[i] != '\0'){
            int j = 0;
            while((trechoString[j]!= '\0') && (textoString[i+j] == trechoString[j])){
                j+=1;
            }
            if(trechoString[j] == '\0'){
                fprintf(fp_saida,"%d,%d\n",i,i+j - 1);
                break;
            }
            i+=1;
        }
    }
    rewind(fp_trechos);

    fclose(fp_texto);
    fclose(fp_trechos);
    fclose(fp_saida);
}