#include <stddef.h>
#include <stdlib.h>

#include "contagemIntersecoes.h"
#include "contagemLeituras.h"
#include "ordenaNumeros.h"
#include "utils.h"

#include "ctrlF.h"


int main(){
    contagemLeituras("res/genoma_grande.txt", "res/pos_genes_grande.csv", "res/fragmentos_pequeno.txt", "build/pos_fragmentos.csv", "build/out.txt");
}
