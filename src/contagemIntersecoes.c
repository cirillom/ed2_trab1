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
    Lista* contagens = criarListaZerada(A->tam);

    ordenaNumeros(A);
    ordenaNumeros(B);

    printListaTuples(A);
    printListaTuples(B);

    size_t primeiro_ib = 0;
    for(size_t ia = 0; ia < A->tam; ia++){
        for(size_t ib = primeiro_ib; ib < B->tam; ib++){
            if(A->val[ia][1] < B->val[ib][0] || A->val[ia][0] > B->val[ib][1]){
                if(contagens->val[ia] == 0){
                    primeiro_ib = ib;
                }
            }else{
                (contagens->val[ia])++;
            }
        }
    }

    printLista(contagens);

    return contagens;
}