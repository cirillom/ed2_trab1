#include <stddef.h>
#include <stdlib.h>

#include "contagemIntersecoes.h"
#include "contagemLeituras.h"
#include "ordenaNumeros.h"
#include "utils.h"

#include "ctrlF.h"


int main(){
    ctrlF("res/nomes.txt", "res/nomesFragmentos.txt","build/pos_fragmentos.csv");
    ctrlFStrStr("res/nomes.txt", "res/nomesFragmentos.txt","build/pos_fragmentos_strstr.csv");
}
