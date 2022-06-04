#include <stddef.h>
#include <stdlib.h>

#include "contagemIntersecoes.h"
#include "ordenaNumeros.h"
#include "utils.h"


int main(){
    //contagemIntersecoesArquivo("res/A.csv", "res/B.csv", "build/out.csv");
    ListaTuples* A = lerListaTuples("res/t.csv");
    ordenaNumeros(A);
    for(size_t i = 0; i < A->tam; i++){
        printf("%d, %d\n", A->val[i][0], A->val[i][1]);
    }
}
