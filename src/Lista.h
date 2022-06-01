#ifndef __LISTA_H__
#define __LISTA_H__

#include <stddef.h>

//a struct Lista define um TAD de lista de numeros inteiros com funcoes uteis
typedef struct {
    int* val;
    size_t tam;
    size_t tamalocado;
} Lista;


//criarLista cria uma Lista de tamanho tam com valores nao especificados
Lista* criarLista(size_t tam);

//criarListaZerada cria uma Lista de tamanho tam com zeros
Lista* criarListaZerada(size_t tam);

//printLista coloca os valores de uma Lista na tela
void printLista(Lista* l);

//adicionarLista adiciona um elemento n no final de l,
//aumentando seu tamanho em um
void adicionarLista(Lista* l, int n);

//deletarLista libera a memoria utilizada pela Lista L
void deletarLista(Lista* l);

#endif