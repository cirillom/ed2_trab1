#ifndef __CTRLF_H__
#define __ORDENA_NUMEROS_H__

#include <stdio.h>

int CountCharFile(FILE* fp);

int CountCharLine(FILE* fp);

int CountLinesFile(FILE* fp);

void ctrlF(char* arq_texto, char* arq_trechos, char* arq_saida);

void ctrlFStrStr(char* arq_texto, char* arq_trechos, char* arq_saida);

#endif