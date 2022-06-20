#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "ctrlF.h"

void ctrlF(char* arq_texto, char* arq_trechos, char* arq_saida){
    FILE* fp_texto = fopen(arq_texto, "r");
    if(fp_texto == NULL) ABORTPROGRAM("%s", arq_texto);

    FILE* fp_trechos = fopen(arq_trechos, "r");
    if(fp_trechos == NULL) ABORTPROGRAM("%s", arq_trechos);

    FILE* fp_saida = fopen(arq_saida, "w");
    if(fp_saida == NULL) ABORTPROGRAM("%s", arq_saida);
    
    int countChar = CountCharFile(fp_texto) + 1;

    char* textoString = malloc(sizeof(char)*countChar);

    fgets(textoString,countChar,fp_texto);

    int numberOfLinesInTrechos = CountLinesFile(fp_trechos);

    int* countOfCharForLine = malloc(sizeof(int)* numberOfLinesInTrechos);

    for(int i = 0;i<numberOfLinesInTrechos;i++){
        int charsInLine = CountCharLine(fp_trechos)+1;
        countOfCharForLine[i] = charsInLine;
    }
    rewind(fp_trechos);

    for(int i = 0;i<numberOfLinesInTrechos;i++){

        char* trechoString = malloc(sizeof(char) * (countOfCharForLine[i]));

        fgets(trechoString,countOfCharForLine[i],fp_trechos);

        trechoString[strlen(trechoString)] = '\0';
        
        fgetc(fp_trechos);

        int j = 0;

        while(textoString[j] != '\0'){
            int k = 0;

            while((trechoString[k]!= '\0') && (textoString[j+k] == trechoString[k])){
                k+=1;
            }
            if(trechoString[k] == '\0'){
                fprintf(fp_saida,"%d,%d\n",j,j+k - 1);
                break;
            }
            j+=1;
        }
        free(trechoString);
    }

    free(countOfCharForLine);
    free(textoString);

    fclose(fp_texto);
    fclose(fp_trechos);
    fclose(fp_saida);
}

int CountCharFile(FILE* fp){
    int countChar = 0;
    char c;
    for (c = getc(fp); c != EOF; c = getc(fp)){
        countChar = countChar + 1;
    }
    rewind(fp);
    return countChar;
}

int CountLinesFile(FILE* fp){

    int countLine = 0;
    char c;
    for (c = getc(fp); c != EOF; c = getc(fp)){
        if (c == '\n'){
            countLine = countLine + 1;
        }
    }
    rewind(fp);
    return countLine;
}

int CountCharLine(FILE* fp){
    int countChar = 0;
    char c;
    for (c = getc(fp); c != EOF && c != '\n'; c = getc(fp)){
        countChar = countChar + 1;
    }
    return countChar;
}

void ctrlFStrStr(char* arq_texto, char* arq_trechos, char* arq_saida){

    FILE* fp_texto = fopen(arq_texto, "r");
    if(fp_texto == NULL) ABORTPROGRAM("%s", arq_texto);

    FILE* fp_trechos = fopen(arq_trechos, "r");
    if(fp_trechos == NULL) ABORTPROGRAM("%s", arq_trechos);

    FILE* fp_saida = fopen(arq_saida, "w");
    if(fp_saida == NULL) ABORTPROGRAM("%s", arq_saida);
    
    int countChar = CountCharFile(fp_texto) + 1;
    char* textoString = malloc(sizeof(char)*(countChar));
    fgets(textoString,countChar,fp_texto);

    int numberOfLinesInTrechos = CountLinesFile(fp_trechos);

    int* countOfCharForLine = malloc(sizeof(int)* numberOfLinesInTrechos);

    for(int i = 0;i<numberOfLinesInTrechos;i++){
        int charsInLine = CountCharLine(fp_trechos)+1;
        countOfCharForLine[i] = charsInLine;
    }
    rewind(fp_trechos);

    for(int i = 0;i<numberOfLinesInTrechos;i++){

        char* trechoString = malloc(sizeof(char) * (countOfCharForLine[i]));

        fgets(trechoString,countOfCharForLine[i],fp_trechos);

        trechoString[strlen(trechoString)] = '\0';
        
        fgetc(fp_trechos);

        char* pointer = strstr(textoString,trechoString);
        if(pointer == NULL){
            continue;
        }
        int pos = pointer - textoString;
        fprintf(fp_saida,"%d,%ld\n",pos,pos + strlen(trechoString)-1);

        free(trechoString);
    }

    free(countOfCharForLine);
    free(textoString);

    fclose(fp_texto);
    fclose(fp_trechos);
    fclose(fp_saida);
}