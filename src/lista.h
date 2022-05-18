#ifndef __LISTA_H__
#define __LISTA_H__

#include <stddef.h>


typedef struct {
    int* val;
    size_t tam;
} lista;

lista* criarLista(size_t tam);
void deletarLista(lista* l);

#endif