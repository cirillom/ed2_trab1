#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "utils.h"


void erroFatal(int linha, char* arq, char* fmt, ...){
    int errno_inicial = errno; //errno pode mudar de valor nos printfs

    //coloca a linguagem como pt_BR (para strerror sair em portugues)
    setlocale(LC_ALL, "pt_BR.utf8");

    va_list ap;

    va_start(ap, fmt);

    fprintf(stderr, "Erro na linha %d do arquivo %s: ", linha, arq);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ": %s\n", strerror(errno_inicial));

    va_end(ap);

    exit(EXIT_FAILURE);
}