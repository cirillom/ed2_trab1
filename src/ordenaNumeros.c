#include <stddef.h>

#include "ordenaNumeros.h"
#include "utils.h"

void ordenaDigitos(ListaTuples* lt, int exp){
    ListaTuples* output = criarListaTuples(lt->tam, lt->col);
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
        int index = (lt->val[i][0] / exp) % 10;
        memcpy(output->val[count[index] - 1], lt->val[i], sizeof(int)*lt->col);
        count[index]--;
    }
  
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < lt->tam; i++){
        memcpy(lt->val[i], output->val[i], sizeof(int)*lt->col);
    }
}

void ordenaNumeros(ListaTuples* lt){
    size_t indice_max = obterMax(lt);
    int m = lt->val[indice_max][0];

    for (int exp = 1; m / exp > 0; exp *= 10)
        ordenaDigitos(lt, exp);
}