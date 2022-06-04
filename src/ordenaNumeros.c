#include <stddef.h>

#include "ordenaNumeros.h"
#include "utils.h"

void ordenaDigitos(ListaTuples* lt, int exp){
    ListaTuples* saida = criarListaTuples(lt->tam, lt->col);
    int count[10] = { 0 };

    for (size_t i = 0; i < lt->tam; i++)
        count[(lt->val[i][0] / exp) % 10]++;
  
    for (size_t i = 1; i < 10; i++)
        count[i] += count[i - 1];
  
    for (int i = (int)lt->tam - 1; i >= 0; i--) {
        int index = (lt->val[i][0] / exp) % 10;
        memcpy(saida->val[count[index] - 1], lt->val[i], sizeof(int)*lt->col);
        count[index]--;
    }
  
    for (size_t i = 0; i < lt->tam; i++){
        memcpy(lt->val[i], saida->val[i], sizeof(int)*lt->col);
    }
    deletarListaTuples(saida);
}

void ordenaNumeros(ListaTuples* lt){
    int m = obterMax(lt);

    for (int exp = 1; m / exp > 0; exp *= 10)
        ordenaDigitos(lt, exp);
}