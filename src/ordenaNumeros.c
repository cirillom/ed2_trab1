#include <stddef.h>

#include "ordenaNumeros.h"
#include "ListaTuples.h"


void swap(ListaTuples* lt, size_t a, size_t b){
    int* tmp = lt->val[a];
    lt->val[a] = lt->val[b];
    lt->val[b] = tmp; 
}

void ordenaNumeros(ListaTuples* lt){
    for(size_t i = 0; i < lt->tam; i++){
        for(size_t j = 0; j < lt->tam-i-1; j++){
            if(lt->val[j][0] > lt->val[j+1][0]){
                swap(lt, j, j+1);
            }
        }
    }
}