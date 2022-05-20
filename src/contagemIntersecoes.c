#include <stddef.h>
#include <stdio.h>

#include "contagemIntersecoes.h"
#include "ordenaNumeros.h"
#include "Lista.h"
#include "utils.h"
#include "ListaTuples.h"


int tupleContem(int* ta, int* tb);


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

int tupleContem(int* ta, int* tb){
    return ta[1] >= tb[0] && ta[0] <= tb[1];
}

Lista* contagemIntersecoes(ListaTuples* A, ListaTuples* B){
    Lista* contagens = criarListaZerada(A->tam);

    ordenaNumeros(A);
    ordenaNumeros(B);


    size_t primeiro_ib = 0;
    for(size_t ia = 0; ia < A->tam; ia++){
        for(size_t ib = primeiro_ib; ib < B->tam; ib++){
            if(tupleContem(A->val[ia], B->val[ib])){
                (contagens->val[ia])++;
            } 
            else if(contagens->val[ia] == 0){
                primeiro_ib = ib;
            }
        }
    }

    return contagens;
}

Lista* contagemIntersecoesMelhorada(ListaTuples* A, ListaTuples* B){
    Lista* contagens = criarListaZerada(A->tam);

    ordenaNumeros(A);
    ordenaNumeros(B);


    size_t ai = 0, bi = 0;
    while(ai < A->tam && bi < B->tam){
        if(tupleContem(A->val[ai], B->val[bi])){
            (contagens->val[ai])++;
        }

        if(A->val[ai][1] < B->val[bi][1]){
            ai++;
        }
        else{
            bi++;
        }
    }
    return contagens;
}