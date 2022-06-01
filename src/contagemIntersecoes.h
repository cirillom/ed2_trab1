#ifndef __CONTAGEM_INTERSECOES_H__
#define __CONTAGEM_INTERSECOES_H__

#include "Lista.h"
#include "ListaTuples.h"


/*
 * contagemIntersecoesArquivo le as ListaTuples no arquivo arq_a e arq_b e
 * executa contagemIntersecoes nesses arquivos, colocando o resultado em
 * arq_out
 */
void contagemIntersecoesArquivo(char* arq_A, char* arq_B, char* arq_out);

/*
 * cotagemIntersecoes conta o numero de intersecoes de cada intervalo em B com
 * cada intervalo em A, retornando uma Lista contendo o número de intersecoes
 * de Bs em cada intervalo de A
 */
Lista* contagemIntersecoes(ListaTuples* A, ListaTuples* B);

/*
 * contagemIntersecoesMelhorada faz o mesmo que contagemIntersecoes, mas em
 * tempo linear (O(A->tam + B->tam))
 */
Lista* contagemIntersecoesMelhorada(ListaTuples* A, ListaTuples* B);

#endif