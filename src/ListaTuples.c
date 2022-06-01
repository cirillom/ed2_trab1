#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "ListaTuples.h"
#include "utils.h"


ListaTuples* criarListaTuples(size_t tam, size_t col){
    if(col < 2){
        return NULL;
    }

    ListaTuples* lt;
    XALLOC(ListaTuples, lt, 1);
    XALLOC(int*, lt->val, tam);


    for(size_t i = 0; i < tam; i++){
        XALLOC(int, lt->val[i], col);
    }

    lt->tam = tam;
    lt->tamalocado = tam;
    lt->col = col;
    return lt;
}

ListaTuples* lerListaTuples(char* arq){
    FILE* fp = fopen(arq, "r");
    if(fp == NULL){
        ABORTPROGRAM("%s", arq);
    }

    ListaTuples* lt = criarListaTuples(0, 2);

    while(1){
        int lidos[2];
        int ret = fscanf(fp, "%d,%d", lidos, lidos+1);
        
        if(ret == EOF){
            break;
        }
        if(ret < 2){
            errno = EINVAL;
            ABORTPROGRAM("arq %s inice %d", arq, lt->tam);
        }
        
        adicionarListaTuples(lt, lidos);
    }
    
    fclose(fp);
    return lt;
}

void printListaTuples(ListaTuples* lt){
    printf("{\n");
    for(size_t i = 0; i < lt->tam; i++){
        printf("  (");

        for(size_t j = 0; j < lt->col; j++){
            printf("%d, ", lt->val[i][j]);
        }

        printf("\b\b)\n");
    }
    printf("\n}\n\n");
}

size_t obterMax(ListaTuples* lt){
    size_t mx = 0;
    for (size_t i = 1; i < lt->tam; i++)
        if (lt->val[i][0] > lt->val[i][mx])
            mx = i;
    return mx;
}

void adicionarListaTuples(ListaTuples* lt, int* c){
    if(lt->tam == lt->tamalocado){
        //feito pelo mesmo raciocinio de uso de memoria que em Lista.c
        lt->tamalocado = (lt->tamalocado == 0)? 2 : lt->tamalocado*2;
        XREALLOC(int*, lt->val, lt->tamalocado);
    }

    XALLOC(int, (lt->val)[lt->tam], lt->col);
    memcpy(lt->val[lt->tam], c, sizeof(int)*lt->col);

    (lt->tam)++;
}

void deletarListaTuples(ListaTuples* lt){
    for(size_t i = 0; i < lt->tam; i++){
        free((lt->val)[i]);
    }
    free(lt->val);
    free(lt);
}