#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"


void fatalError(int line, char* file, char* fmt, ...){
    int init_errno = errno; //errno pode mudar de valor em vfprintf

    va_list ap;

    va_start(ap, fmt);

    fprintf(stderr, "Error at line %d of file %s: ", line, file);
    vfprintf(stderr, fmt, ap);
    printf(": %s\n", strerror(init_errno));

    va_end(ap);

    exit(EXIT_FAILURE);
}