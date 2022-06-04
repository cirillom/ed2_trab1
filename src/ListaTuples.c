#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>

#include "ListaTuples.h"
#include "utils.h"


ListaTuples* criarListaTuples(size_t tam, size_t col){
    if(col < 2){
        errno = EINVAL;
        ABORTPROGRAM("cols");
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

ListaTuples* gerarListaTuplesAleat(size_t tam, size_t col, int cresc, int max){
    ListaTuples* lt = criarListaTuples(tam, col);

    for(size_t i = 0; i < lt->tam; i++){
        for(size_t j = 0; j < lt->col; j++){
            //valores em listaTuples            
            if(cresc){
                int prev = (j == 0)? 0: lt->val[i][j-1];
                lt->val[i][j] = rand() % (max-prev) + prev;
            }
            else{
                lt->val[i][j] = rand();
            }
        }
    }
    return lt;
}

void printListaTuples(ListaTuples* lt, FILE* arq){
    fprintf(arq, "{\n");
    for(size_t i = 0; i < lt->tam; i++){
        fprintf(arq, "  (");

        for(size_t j = 0; j < lt->col; j++){
            fprintf(arq, "%d", lt->val[i][j]);
            
            if(j != lt->col-1){
                fprintf(arq, ", ");
            }
        }

        fprintf(arq, ")\n");
    }
    fprintf(arq, "}\n\n");
}

int obterMax(ListaTuples* lt){
    int mx = lt->val[0][0];

    for (size_t i = 1; i < lt->tam; i++)
        if (lt->val[i][0] > mx)
            mx = lt->val[i][0];

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