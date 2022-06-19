#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenaNumeros.h"
#include "utils.h"

const char* ajuda = 
"argumentos de linha de comando:\n"
"1) numero de testes a se fazer\n"
"2) numero de elementos nas ListaTuples A e B\n"
"3) (opcional) incremento em multiplos de argv[2] para se fazer a cada teste\n"
"4) (opcional) numero de testes a se fazer antes de aplicar o incremento\n"
"5) (opcional) valor maximo contido nas ListaTuples aleatorias A e B\n"
"exemplo: %s 10 1000 2 5\n"
"o exemplo vai realizar 10*5 testes e mostrar 10 tempos na tela, sendo que a\n"
"cada 5 testes ele coloca a media dos tempos na tela e multiplica o numero\n"
"de elementos por 2\n";

int main(int argc, char** argv){
    srand(time(NULL));

    if( argc < 3 || argc > 6 ||
        strcmp("-h", argv[1]) == 0 ||
        strcmp("--help", argv[1]) == 0
    ){
        printf(ajuda, argv[0]);
        exit(0);
    }

    int testes, elementos;
    float incremento = 1;
    int testes_por_incremento = 1;
    int max = RAND_MAX;

    if(argc == 6){
        max = atoi(argv[5]);
    }
    if(argc >= 5){
        testes_por_incremento = atoi(argv[4]);
    }
    if(argc >= 4){
        incremento = atof(argv[3]);
    }

    elementos = atoi(argv[2]);
    testes    = atoi(argv[1]);
    
    for(int i = 0; i < testes; i++){
        clock_t tempo = 0;
        for(int j = 0; j < testes_por_incremento; j++){
            time_t inicio;
            ListaTuples* A = gerarListaTuplesAleat(elementos, 2, 1, max);
            
            inicio = clock();
            ordenaNumeros(A);
            tempo += clock() - inicio;

            deletarListaTuples(A);
        }
        tempo /= testes_por_incremento;

        FILE* fp = fopen("res/tempos/ordenaNumeros.csv", "ab");
        //printf("n = %d | tempo = %.6lf\n", elementos,(double) tempo/CLOCKS_PER_SEC);
        printf("%d & %.6lf \\\\ \\hline \n", elementos,(double) tempo/CLOCKS_PER_SEC);
        fprintf(fp, "%d, %.6lf\n", elementos,(double) tempo/CLOCKS_PER_SEC);
        fclose(fp);

        elementos *= incremento;
    }
}
