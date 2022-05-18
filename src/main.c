#include <stddef.h>
#include <stdlib.h>

#include "contagemIntersecoes.h"


int main(){
    Intervalo* inters;
    size_t tamanho = lerIntervalos("res/test.csv", &inters);
    
    for(size_t i = 0; i < tamanho; i++){
        printf("%d, %d\n", inters[i].ini, inters[i].fim);
    }

    deletarIntervalos(inters);
}
