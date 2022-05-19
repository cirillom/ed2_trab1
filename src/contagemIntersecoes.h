#ifndef __CONTAGEM_INTERSECOES_H__
#define __CONTAGEM_INTERSECOES_H__

#include "Lista.h"
#include "ListaTuples.h"

size_t lerIntervalos(char* arq, ListaTuples** out);
void deletarIntervalos(ListaTuples* intervalos);

void contagemIntersecoesArquivo(char* arq_A, char* arq_B, char* arq_out);
Lista* contagemIntersecoes(ListaTuples* A, ListaTuples* B);

#endif