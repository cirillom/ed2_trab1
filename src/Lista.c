#include <string.h>
#include <stddef.h>

#include "Lista.h"
#include "utils.h"


Lista* criarLista(size_t tam){
    Lista* l;
    XALLOC(Lista, l, 1);

    l->tam = tam;
    l->tamalocado = tam;
    XALLOC(int, l->val, tam);

    return l;
}

Lista* criarListaZerada(size_t tam){
    Lista* l = criarLista(tam);
    memset(l->val, 0, tam*sizeof(int));
    return l;
}

void deletarLista(Lista *l){
    free(l->val);
    free(l);
}