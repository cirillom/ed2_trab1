#include <string.h>
#include <stddef.h>
#include <stdio.h>

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

void printLista(Lista* l, FILE* arq){
    fprintf(arq, "{");
    for(size_t i = 0; i < l->tam; i++){
        fprintf(arq, "%d", l->val[i]);
        
        if(i != l->tam - 1){
            fprintf(arq, ", ");
        }
    }
    fprintf(arq, "}\n");
}

void adicionarLista(Lista* l, int n){
    if(l->tam == l->tamalocado){
        //se o tamanho alocado for igual ao tamanho utilizado, aloca o dobro do
        //tamanho utilizado, isso nao e ideal para aplicacoes muito grandes mas
        //para uma lista que utilize ate 400Mb e aceitavel
        l->tamalocado = (l->tamalocado == 0)? 2 : l->tamalocado*2;
        XREALLOC(int, l->val, l->tamalocado);
    }

    l->val[l->tam] = n;
    l->tam++;
}

int compararListas(Lista* a, Lista* b){
    if(a->tam != b->tam){
        return 0;
    }

    for(size_t i = 0; i < a->tam; i++){
        if(a->val[i] != b->val[i]){
            return 0;
        }
    }

    return 1;
}

void deletarLista(Lista *l){
    free(l->val);
    free(l);
}