#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "contagemLeituras.h"

int main(){
    clock_t tempo = 0;
    time_t inicio;
    int testes = 10;

    for (int i = 0; i < testes; i++){
        inicio = clock();
        contagemLeituras("res/genoma_grande.txt", "res/pos_genes_pequeno.csv", "res/fragmentos_grande.txt", "build/pos_fragmentos.csv", "build/out.txt");
        tempo += clock() - inicio;
    }
    tempo /= testes;
    
    printf("%.6lf\n", (double) tempo/CLOCKS_PER_SEC);
}
