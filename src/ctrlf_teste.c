#include <stddef.h>
#include <stdlib.h>

#include "contagemIntersecoes.h"
#include "contagemLeituras.h"
#include "ordenaNumeros.h"
#include "utils.h"

#include "ctrlF.h"


int main(){
    ctrlF("res/genoma_medio.txt", "res/fragmentos_medio.txt","build/pos_fragmentos.csv");
    ctrlFStrStr("res/genoma_medio.txt", "res/fragmentos_medio.txt","build/pos_fragmentos_strstr.csv");
}
