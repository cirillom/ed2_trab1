#include <stddef.h>
#include <stdlib.h>

#include "contagemIntersecoes.h"
#include "contagemLeituras.h"
#include "ordenaNumeros.h"
#include "utils.h"


int main(){
    contagemLeituras("res/genoma_pequeno.txt", "res/pos_genes_pequeno.csv", "res/fragmentos_pequeno.txt", "build/pos_fragmentos.csv", "build/out.txt");
}
