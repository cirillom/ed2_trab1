#ifndef __CONTAGEM_INTERSECOES_H__
#define __CONTAGEM_INTERSECOES_H__

#include <stddef.h>
#include <stdio.h>

#include "utils.h"

/*
 * a struct Intervalo define um intervalo entre dois numeros naturais, de ini
 * até fim inclusivos
 */
typedef struct {
    int ini;
    int fim;
} Intervalo;


size_t lerIntervalos(char* arq, Intervalo** out);
void deletarIntervalos(Intervalo* intervalos);

void contagemIntersecoesArquivo(char* arq_A, char* arq_B, char* arq_out);
int* contagemIntersecoes(Intervalo* A, Intervalo* B);

#endif