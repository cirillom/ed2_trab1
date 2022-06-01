#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>

#include "errno.h"
#include "string.h"

//ABORTPROGRAM aborta o programa, 
//mostrando o arquivo, linha, errno e uma mensagem com interface printf na tela
#define ABORTPROGRAM(...) erroFatal(__LINE__, __FILE__, __VA_ARGS__);

//XALLOC aloca tam elementos de determinado tipo no ponteiro p,
//abortando o programa em caso de falha
#define XALLOC(tipo, p, tam) \
    (p) = malloc(sizeof(tipo)*(tam)); \
    if(!(p)){ \
        ABORTPROGRAM("malloc"); \
    }

//XREALLOC faz o mesmo que XALLOC mas realoca o ponteiro p com novotam
#define XREALLOC(tipo, p, novotam) \
    (p) = realloc(p, sizeof(tipo)*(novotam)); \
    if(!(p)){ \
        ABORTPROGRAM("realloc"); \
    } \


/*
 * erroFatal aborta o programa especificando uma linha e arquivo do erro,
 * alem do errno no momento do erro e uma mensagem formatada estilo printf
 */
void erroFatal(int linha, char* arq, char* fmt, ...);

#endif