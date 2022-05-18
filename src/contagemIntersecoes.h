#ifndef __CONTAGEM_INTERSECOES_H__
#define __CONTAGEM_INTERSECOES_H__

#include <stddef.h>
#include <stdio.h>

#include "utils.h"
#include "lista.h"

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
lista* contagemIntersecoes(Intervalo* A, Intervalo* B, size_t nA, size_t nB);

#endif