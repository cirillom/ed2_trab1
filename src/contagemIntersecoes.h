#ifndef __CONTAGEM_INTERSECOES_H__
#define __CONTAGEM_INTERSECOES_H__

#include "Lista.h"
#include "ListaTuples.h"


void contagemIntersecoesArquivo(char* arq_A, char* arq_B, char* arq_out);
Lista* contagemIntersecoes(ListaTuples* A, ListaTuples* B);
Lista* contagemIntersecoesMelhorada(ListaTuples* A, ListaTuples* B);

#endif