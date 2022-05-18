#ifndef __DADO_H__
#define __DADO_H__

#include "errno.h"
#include "string.h"


#define ABORTPROGRAM(...) fatalError(__LINE__, __FILE__, __VA_ARGS__);

#define XALLOC(type, p, size) \
    (p) = malloc(sizeof(type)*(size)); \
    if(!(p)){ \
        ABORTPROGRAM("malloc"); \
    }

#define XREALLOC(type, p, newsize) \
    (p) = realloc(p, sizeof(type)*newsize); \
    if(!(p)){ \
        ABORTPROGRAM("realloc"); \
    } \


void fatalError(int line, char* file, char* fmt, ...);


#endif