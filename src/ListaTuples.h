#ifndef __LISTA_TUPLES_H__
#define __LISTA_TUPLES_H__

#include <stddef.h>

typedef struct {
    int** val;
    size_t tam;
    size_t tamalocado;
    size_t col;
} ListaTuples;

ListaTuples* criarListaTuples(size_t tam, size_t col);
ListaTuples* lerListaTuples(char* arq);
void printListaTuples(ListaTuples* lt);
int obterMax(ListaTuples* lt);
void adicionarListaTuples(ListaTuples* lt, int* c);
void deletarListaTuples(ListaTuples* lt);

#endif