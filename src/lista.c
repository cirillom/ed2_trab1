

#include "lista.h"
#include "utils.h"


lista* criarLista(size_t tam){
    lista* l;
    XALLOC(lista, l, 1);

    l->tam = tam;
    XALLOC(int, l->val, tam);

    return l;
}

void deletarLista(lista *l){
    free(l->val);
    free(l);
}