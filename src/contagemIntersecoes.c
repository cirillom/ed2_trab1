#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "contagemIntersecoes.h"
#include "lista.h"
#include "utils.h"


size_t lerIntervalos(char* arq, Intervalo** out){
    FILE* fp = fopen(arq, "r");
    if(fp == NULL){
        ABORTPROGRAM("%s", arq);
    }

    size_t tammax = 1;
    XALLOC(Intervalo, *out, 1);

    size_t tam = 0;
    while(1){
        int ini_lido, fim_lido;
        int ret = fscanf(fp, "%d,%d", &ini_lido, &fim_lido);
        
        if(ret == EOF){
            break;
        }
        if(ret < 2){
            errno = EINVAL;
            ABORTPROGRAM("arq %s iteration %d", arq, tam);
        }
        
        (*out)[tam].ini = ini_lido;
        (*out)[tam].fim = fim_lido;
        
        tam++;
        if(tam >= tammax){
            tammax *= 2;
            XREALLOC(Intervalo, *out, tammax);
        }
    }
    
    fclose(fp);

    return tam;
}

void deletarIntervalos(Intervalo* intervalos){
    free(intervalos);
}

void contagemIntersecoesArquivo(char* arq_A, char* arq_B, char* arq_out){
    Intervalo* A;
    Intervalo* B;
    size_t nA = lerIntervalos(arq_A, &A);
    size_t nB = lerIntervalos(arq_B, &B);


    lista* contagens = contagemIntersecoes(A, B, nA, nB);

    FILE* fp = fopen(arq_out, "w");
    for(size_t i = 0; i < contagens->tam; i++){
        fprintf(fp, "%d\n", contagens->val[i]);
    }

    fclose(fp);
    deletarLista(contagens);
    deletarIntervalos(B);
    deletarIntervalos(A);
}

lista* contagemIntersecoes(Intervalo* A, Intervalo* B, size_t nA, size_t nB){
    lista* l = criarLista(0);
    return l;
}