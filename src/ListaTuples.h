#ifndef __LISTA_TUPLES_H__
#define __LISTA_TUPLES_H__

#include <stddef.h>
#include <stdio.h>


//a struct ListaTuples representa uma lista de listas de numeros inteiros de
//tal forma que cada lista contida represente um objeto inseparavel dos outros
//a odenacao de uma ListaTuple se da pela coluna do primeiro elemento,
//uma ListaTuple nunca tem menos que duas colunas
typedef struct {
    int** val;
    size_t tam;
    size_t tamalocado;
    size_t col;
} ListaTuples;


//criarListaTuples cria uma ListaTuples de tamanho tam e col colunas
//com valores nao especificados
ListaTuples* criarListaTuples(size_t tam, size_t col);

//lerListaTuples le uma ListaTuples de duas colunas de um arquivo de nome arq
ListaTuples* lerListaTuples(char* arq);

/*
 * gerarListaTuplesAleat gera uma ListaTuples de tamanho tam e col colunas entre
 * 0 e max inclusivo e coloca valores aletorios nas entradas, sendo que, se 
 * cresc for 1, uma mesma tuple terá valores crescentes
 */
ListaTuples* gerarListaTuplesAleat(size_t tam, size_t col, int cresc, int max);

//printListaTuples coloca em um arquivo arq os valores de uma ListaTuples
void printListaTuples(ListaTuples* lt, FILE* arq);

//obterMax retorna o valor maximo de uma ListaTuples
int obterMax(ListaTuples* lt);

//adicionarListaTuples adiciona no final de lt uma nova tuple c,
//aumentando o tamanho de lt em um
void adicionarListaTuples(ListaTuples* lt, int* c);

//deletarListaTuples deleta uma ListaTuples
void deletarListaTuples(ListaTuples* lt);

#endif