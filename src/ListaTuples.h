#ifndef __LISTA_TUPLES_H__
#define __LISTA_TUPLES_H__

#include <stddef.h>

typedef struct {
    int** val;
    size_t tam;
    size_t tamalocado;
} ListaTuples;

ListaTuples* criarListaTuples(size_t tam);
ListaTuples* lerListaTuples(char* arq);
void printListaTuples(ListaTuples* lt);
void adicionarListaTuples(ListaTuples* lt, int a, int b);
void deletarListaTuples(ListaTuples* lt);

#endif