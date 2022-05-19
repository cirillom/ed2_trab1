#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "ListaTuples.h"
#include "utils.h"


ListaTuples* criarListaTuples(size_t tam){
    ListaTuples* lt;
    XALLOC(ListaTuples, lt, 1);
    XALLOC(int*, lt->val, tam);
    lt->tam = tam;
    lt->tamalocado = tam;

    return lt;
}

ListaTuples* lerListaTuples(char* arq){
    FILE* fp = fopen(arq, "r");
    if(fp == NULL){
        ABORTPROGRAM("%s", arq);
    }

    ListaTuples* lt = criarListaTuples(0);

    while(1){
        int ini_lido, fim_lido;
        int ret = fscanf(fp, "%d,%d", &ini_lido, &fim_lido);
        
        if(ret == EOF){
            break;
        }
        if(ret < 2){
            errno = EINVAL;
            ABORTPROGRAM("arq %s index %d", arq, lt->tam);
        }
        
        adicionarListaTuples(lt, ini_lido, fim_lido);
    }
    
    fclose(fp);
    return lt;
}

void printListaTuples(ListaTuples* lt){
    printf("{\n");
    for(size_t i = 0; i < lt->tam; i++){
        printf("  (%d, %d),\n", lt->val[i][0], lt->val[i][1]);
    }
    printf("}\n\n");
}

void adicionarListaTuples(ListaTuples* lt, int a, int b){
    if(lt->tam == lt->tamalocado){
        lt->tamalocado = (lt->tamalocado == 0)? 2 : lt->tamalocado*2;
        XREALLOC(int*, lt->val, lt->tamalocado);
    }

    XALLOC(int, (lt->val)[lt->tam], 2);
    lt->val[lt->tam][0] = a;
    lt->val[lt->tam][1] = b;
    (lt->tam)++;
}

void deletarListaTuples(ListaTuples* lt){
    for(size_t i = 0; i < lt->tam; i++){
        free((lt->val)[i]);
    }
    free(lt->val);
    free(lt);
}