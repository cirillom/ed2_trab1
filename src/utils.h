#ifndef __DADO_H__
#define __DADO_H__

#include <stdlib.h>

#include "errno.h"
#include "string.h"


#define ABORTPROGRAM(...) fatalError(__LINE__, __FILE__, __VA_ARGS__);

#define XALLOC(type, p, len) \
    (p) = malloc(sizeof(type)*(len)); \
    if(!(p)){ \
        ABORTPROGRAM("malloc"); \
    }

#define XREALLOC(type, p, newlen) \
    (p) = realloc(p, sizeof(type)*(newlen)); \
    if(!(p)){ \
        ABORTPROGRAM("realloc"); \
    } \


void mostrarLista(int arr[], int n);
void fatalError(int line, char* file, char* fmt, ...);


#endif