#ifndef __LISTA_H__
#define __LISTA_H__

#include <stddef.h>
#include <stdio.h>

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

//printLista coloca os valores de uma Lista em um arquivo arq
void printLista(Lista* l, FILE* arq);

//adicionarLista adiciona um elemento n no final de l,
//aumentando seu tamanho em um
void adicionarLista(Lista* l, int n);

//comararListas retorna 1 se as listas sao iguais e zero se forem diferentes
int compararListas(Lista* a, Lista* b);

//deletarLista libera a memoria utilizada pela Lista L
void deletarLista(Lista* l);

#endif