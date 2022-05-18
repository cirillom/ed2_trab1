#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "contagemIntersecoes.h"
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
        (*out)[tam].ini = ini_lido;
        (*out)[tam].fim = fim_lido;

        if(ret == EOF){
            break;
        }

        if(ret < 2){
            errno = EINVAL;
            ABORTPROGRAM("arq %s iteration %d", arq, tam);
        }

        tam++;
        if(tam >= tammax){
            tammax*=2;
            XREALLOC(Intervalo, *out, tammax);
        }
    }
    
    return tam;
}

void deletarIntervalos(Intervalo *intervalos){
    free(intervalos);
}