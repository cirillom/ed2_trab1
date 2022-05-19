#include <stddef.h>

#include "ordenaNumeros.h"
#include "ListaTuples.h"


void swap(ListaTuples* lt, size_t a, size_t b){
    int* tmp = lt->val[a];
    lt->val[a] = lt->val[b];
    lt->val[b] = tmp; 
}

size_t part(ListaTuples* lt, size_t start, size_t end){
    int endel = lt->val[end][0];

    size_t smaller_index = start;
    for(size_t i = start; i < end; i++){
        if(lt->val[i][0] < endel){
            swap(lt, i, smaller_index);
            smaller_index++;
        }
    }

    swap(lt, smaller_index, end);
    return smaller_index;
}

void quicksort(ListaTuples* lt, size_t start, size_t end){

    if(start >= end){
        return;
    }

    size_t part_index = part(lt, start, end);

    quicksort(lt, start, (part_index == 0)? 0 : part_index-1);
    quicksort(lt, part_index+1, end);

}

void ordenaNumeros(ListaTuples* lt){
    quicksort(lt, 0, lt->tam-1);
}