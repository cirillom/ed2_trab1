#include <stddef.h>
#include <stdio.h>

#include "contagemIntersecoes.h"
#include "ctrlF.h"
#include "Lista.h"
#include "utils.h"
#include "ListaTuples.h"

void contagemLeituras(char* arq_genoma, char* arq_genes, char* arq_fragmentos, char* arq_pos_frags, char* arq_saida){
    ctrlF(arq_genoma, arq_fragmentos, arq_pos_frags);
    contagemIntersecoesArquivo(arq_genes, arq_pos_frags, arq_saida);
}