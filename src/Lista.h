#ifndef __LISTA_H__
#define __LISTA_H__

#include <stddef.h>


typedef struct {
    int* val;
    size_t tam;
    size_t tamalocado;
} Lista;

Lista* criarLista(size_t tam);
Lista* criarListaZerada(size_t tam);
void printLista(Lista* l);
void adicionarLista(Lista* l, int n);
void deletarLista(Lista* l);

#endif