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

#define EM_A   (0<<31)
#define EM_B   (1<<31)

Lista* contagemIntersecoesMelhorada(ListaTuples* A, ListaTuples* B){
    Lista* contagens = criarListaZerada(A->tam);

    ListaTuples* C = criarListaTuples(2*(A->tam+B->tam));

    size_t i = 0;
    for(size_t ib = 0; ib < B->tam; ib++, i+=2){
        C->val[i][0] = B->val[ib][0];
        C->val[i][1] = EM_B|ib;
        
        C->val[i+1][0] = B->val[ib][1]+1;
        C->val[i+1][1] = EM_B|ib;
    }

    for(size_t ia = 0; ia < A->tam; ia++, i+=2){
        C->val[i][0] = A->val[ia][0];
        C->val[i][1] = EM_A|ia;
        
        C->val[i+1][0] = A->val[ia][1];
        C->val[i+1][1] = EM_A|ia;
    }


    ordenaNumeros(C);
    printListaTuples(C);

    Lista* estados_a = criarListaZerada(A->tam);
    Lista* estados_b = criarListaZerada(B->tam);

    int abertos_b = 0;
    int fechados_b = 0;
    for(i = 0; i < C->tam; i++){
        if(C->val[i][1]&EM_B){

            size_t ib = ((C->val[i][1])<<1)>>1;
            
            if(estados_b->val[ib] == 0){
                estados_b->val[ib] = 1;
                abertos_b++;
            }
            else{
                fechados_b++;
            }
        }
        else {

            size_t ia = ((C->val[i][1])<<1)>>1;

            if(estados_a->val[ia] == 0){
                estados_a->val[ia] = 1;
                contagens->val[ia] = fechados_b;
            }
            else {
                contagens->val[ia] = abertos_b - contagens->val[ia];
            }
        }
    }

    deletarListaTuples(C);

    return contagens;
}