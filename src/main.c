#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "contagemLeituras.h"

int main(){
    clock_t tempo = 0;
    time_t inicio;

    inicio = clock();
    contagemLeituras("res/genoma_pequeno.txt", "res/pos_genes_grande.csv", "res/fragmentos_grande.txt", "build/pos_fragmentos.csv", "build/out.txt");
    tempo = clock() - inicio;    
    printf("%.6lf\n", (double) tempo/CLOCKS_PER_SEC);

    inicio = clock();
    contagemLeituras("res/genoma_medio.txt", "res/pos_genes_grande.csv", "res/fragmentos_grande.txt", "build/pos_fragmentos.csv", "build/out.txt");
    tempo = clock() - inicio;    
    printf("%.6lf\n", (double) tempo/CLOCKS_PER_SEC);
    
    inicio = clock();
    contagemLeituras("res/genoma_grande.txt", "res/pos_genes_pequeno.csv", "res/fragmentos_grande.txt", "build/pos_fragmentos.csv", "build/out.txt");
    tempo = clock() - inicio;    
    printf("%.6lf\n", (double) tempo/CLOCKS_PER_SEC);
    
    inicio = clock();
    contagemLeituras("res/genoma_grande.txt", "res/pos_genes_medio.csv", "res/fragmentos_grande.txt", "build/pos_fragmentos.csv", "build/out.txt");
    tempo = clock() - inicio;    
    printf("%.6lf\n", (double) tempo/CLOCKS_PER_SEC);
    
    inicio = clock();
    contagemLeituras("res/genoma_grande.txt", "res/pos_genes_grande.csv", "res/fragmentos_pequeno.txt", "build/pos_fragmentos.csv", "build/out.txt");
    tempo = clock() - inicio;    
    printf("%.6lf\n", (double) tempo/CLOCKS_PER_SEC);
    
    inicio = clock();
    contagemLeituras("res/genoma_grande.txt", "res/pos_genes_grande.csv", "res/fragmentos_medio.txt", "build/pos_fragmentos.csv", "build/out.txt");
    tempo = clock() - inicio;    
    printf("%.6lf\n", (double) tempo/CLOCKS_PER_SEC);
    
    inicio = clock();
    contagemLeituras("res/genoma_grande.txt", "res/pos_genes_grande.csv", "res/fragmentos_grande.txt", "build/pos_fragmentos.csv", "build/out.txt");
    tempo = clock() - inicio;    
    printf("%.6lf\n", (double) tempo/CLOCKS_PER_SEC);
    
}
