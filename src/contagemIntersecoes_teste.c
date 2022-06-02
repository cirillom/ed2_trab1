#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "contagemIntersecoes.h"
#include "utils.h"


void gerarDumpInputs(ListaTuples* A, ListaTuples* B, char* nome_arq){
    FILE* arq = fopen(nome_arq, "w");
    if(arq == NULL){
        ABORTPROGRAM("%s", nome_arq);
    }

    printListaTuples(A, arq);
    fprintf(arq, "\n");
    printListaTuples(B, arq);
}

void gerarDump(Lista* l, char* nome_arq){
    FILE* arq = fopen(nome_arq, "w");
    if(arq == NULL){
        ABORTPROGRAM("%s", nome_arq);
    }

    printLista(l, arq);
}

/*
 * argumentos:
 * 1) numero de testes a se fazer
 * 2) numero de elementos nas ListaTuples A e B
 * 3) (opcional) incremento em multiplos de argv[2] para se fazer a cada teste
 * 4) (opcional) numero de testes a se fazer antes de aplicar o incremento
 * 5) (opcional) valor maximo contido nas ListaTuples aleatorias A e B
 * exemplo: ./main 10 1000 2 5
 * o exemplo vai realizar 10*5 testes e mostrar 10 tempos na tela, sendo que a
 * cada 5 testes ele coloca a media dos tempos na tela e multiplica o numero de
 * elementos por 2
 */
int main(int argc, char** argv){
    srand(time(NULL));

    int testes, elementos;
    int incremento = 1, testes_por_incremento = 1;
    int max = RAND_MAX;

    if(argc < 3|| argc > 6){
        fprintf(stderr, "argc deve estar entre 3 e 6");
        exit(1);
    }
    if(argc == 6){
        max = atoi(argv[5]);
    }
    if(argc >= 5){
        testes_por_incremento = atoi(argv[4]);
    }
    if(argc >= 4){
        incremento = atoi(argv[3]);
    }

    elementos = atoi(argv[2]);
    testes    = atoi(argv[1]);
    
    for(int i = 0; i < testes; i++){
        clock_t tempo_normal = 0;
        clock_t tempo_melhorada = 0;
        for(int j = 0; j < testes_por_incremento; j++){
            time_t inicio;
            ListaTuples* A = gerarListaTuplesAleat(elementos, 2, 1, max);
            ListaTuples* B = gerarListaTuplesAleat(elementos, 2, 1, max);
            
            inicio = clock();
            Lista* contagens_normal = contagemIntersecoes(A, B);
            tempo_normal += clock() - inicio;

            inicio = clock();
            Lista* contagens_melhorada = contagemIntersecoesMelhorada(A, B);
            tempo_melhorada += clock() - inicio;

            if(compararListas(contagens_normal, contagens_melhorada) != 1){
                fprintf(stderr, "Erro! Listas nao sao iguais!\n");
                fprintf(stderr, "gerando dump\n");
                gerarDumpInputs(A, B, "build/input.txt");
                gerarDump(contagens_normal, "build/normal.txt");
                gerarDump(contagens_melhorada, "build/melhorara.txt");
                exit(-1);
            }
        }
        tempo_normal /= testes_por_incremento;
        tempo_melhorada /= testes_por_incremento;

        printf("normal = %ld, melhorada = %ld\n", tempo_normal, tempo_melhorada);

        elementos *= incremento;
    }
}
