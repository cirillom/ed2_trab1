#include <stddef.h>

#include "ordenaNumeros.h"
#include "utils.h"

void ordenaDigitos(ListaTuples* lt, int exp){
    ListaTuples* output = criarListaTuples(lt->tam);
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < lt->tam; i++)
        count[(lt->val[i][0] / exp) % 10]++;
  
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
  
    // Build the output array
    for (i = lt->tam - 1; i >= 0; i--) {
        output->val[count[(lt->val[i][0] / exp) % 10] - 1][0] = lt->val[i][0];
        output->val[count[(lt->val[i][0] / exp) % 10] - 1][1] = lt->val[i][1];
        count[(lt->val[i][0] / exp) % 10]--;
    }
  
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < lt->tam; i++){
        lt->val[i][0] = output->val[i][0];
        lt->val[i][1] = output->val[i][1];
    }
}

void ordenaNumeros(ListaTuples* lt){
    int m = obterMax(lt);
  
    for (int exp = 1; m / exp > 0; exp *= 10)
        ordenaDigitos(lt, exp);
}