#include <stddef.h>
#include <stdio.h>


#include "contagemIntersecoes.h"
#include "ordenaNumeros.h"
#include "Lista.h"
#include "utils.h"
#include "ListaTuples.h"

void contagemIntersecoesArquivo(char* arq_A, char* arq_B, char* arq_out){
    ListaTuples* A = lerListaTuples(arq_A);
    ListaTuples* B = lerListaTuples(arq_B);


    Lista* contagens = contagemIntersecoes(A, B);

    FILE* fp = fopen(arq_out, "w");
    if(fp == NULL){
        ABORTPROGRAM("%s", arq_out);
    }
    for(size_t i = 0; i < contagens->tam; i++){
        fprintf(fp, "%d\n", contagens->val[i]);
    }

    fclose(fp);
    deletarLista(contagens);
    deletarListaTuples(B);
    deletarListaTuples(A);
}

Lista* contagemIntersecoes(ListaTuples* A, ListaTuples* B){
    Lista* l = criarListaZerada(A->tam);

    ordenaNumeros(A);
    ordenaNumeros(B);

    printListaTuples(A);
    printListaTuples(B);

    return l;
}