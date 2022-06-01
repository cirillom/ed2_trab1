#include <stddef.h>
#include <stdio.h>

#include "contagemIntersecoes.h"
#include "ordenaNumeros.h"
#include "Lista.h"
#include "utils.h"
#include "ListaTuples.h"

#define EM_A 1
#define EM_B 0


/*
 * tupleContem retorna 1 se o intervalo tb tem algum elemento em comum com ta,
 * ou seja, se ta contem elementos de tb
 */
int tupleContem(int* ta, int* tb);


void contagemIntersecoesArquivo(char* arq_A, char* arq_B, char* arq_out){
    ListaTuples* A = lerListaTuples(arq_A);
    ListaTuples* B = lerListaTuples(arq_B);


    Lista* contagens = contagemIntersecoes(A, B);
    
    //abre o arquivo de saida
    FILE* fp = fopen(arq_out, "w");
    if(fp == NULL){
        ABORTPROGRAM("%s", arq_out);
    }

    //para cada contagem, escreve no arquivo
    for(size_t i = 0; i < contagens->tam; i++){
        fprintf(fp, "%d\n", contagens->val[i]);
    }

    fclose(fp);
    deletarLista(contagens);
    deletarListaTuples(B);
    deletarListaTuples(A);
}

int tupleContem(int* ta, int* tb){
    return ta[1] >= tb[0] && ta[0] <= tb[1];
}

Lista* contagemIntersecoes(ListaTuples* A, ListaTuples* B){
    //se nao tivermos listaTuples com duas colunas, A ou B nao sao compostos
    //por intervalos de numeros inteiros
    if(B->col != 2 || A->col != 2){
        errno = EINVAL;
        ABORTPROGRAM("colunas em A ou B");
    }

    Lista* contagens = criarListaZerada(A->tam);

    //ordena ambas as ListaTuples
    ordenaNumeros(A);
    ordenaNumeros(B);


    size_t primeiro_ib = 0;
    for(size_t ia = 0; ia < A->tam; ia++){
        for(size_t ib = primeiro_ib; ib < B->tam; ib++){

            //para cada elemento de A e B, ve se um esta contido no outro 
            if(tupleContem(A->val[ia], B->val[ib])){
                (contagens->val[ia])++;
            } 
            else if(contagens->val[ia] == 0){
                //guarda o ultimo ib que nao estava contido no A[ia] anteirior
                primeiro_ib = ib;
            }
        }
    }

    return contagens;
}

Lista* contagemIntersecoesMelhorada(ListaTuples* A, ListaTuples* B){
    //se nao tivermos listaTuples com duas colunas, A ou B nao sao compostos
    //por intervalos de numeros inteiros
    if(B->col != 2 || A->col != 2){
        errno = EINVAL;
        ABORTPROGRAM("colunas em A ou B");
    }

    Lista* contagens = criarListaZerada(A->tam);

    ListaTuples* C = criarListaTuples(2*(A->tam+B->tam), 3);

    //para cada elemento em B e depois em A (a ordem e importante)
    size_t i = 0;
    for(size_t ib = 0; ib < B->tam; ib++, i+=2){
        C->val[i][0] = B->val[ib][0]; //guarda o valor do inicio de B[ib]
        C->val[i][1] = ib; //guarda a posicao no vetor B original
        C->val[i][2] = EM_B; //avisa que a entrada e do vetor B
        
        //o mesmo para o final

        //soma 1 para o final de B ter prioridade menor nas contagens,
        //o que da o carater inclusivo dos intervalos
        C->val[i+1][0] = B->val[ib][1]+1;
        C->val[i+1][1] = ib;
        C->val[i+1][2] = EM_B;
    }

    //o mesmo para todo A[ia]
    for(size_t ia = 0; ia < A->tam; ia++, i+=2){
        C->val[i][0] = A->val[ia][0];
        C->val[i][1] = ia;
        C->val[i][2] = EM_A;
        
        C->val[i+1][0] = A->val[ia][1];
        C->val[i+1][1] = ia;
        C->val[i+1][2] = EM_A;
    }


    //ordena a ListaTuples C com um stable sort, o que faz com que elementos de
    //B com o mesmo valor estejam sempre antes de elementos de A
    ordenaNumeros(C);

    //guarda o estado de cada entrada na lista: 
    //se ja passou pelo index de comeco (1) ou nao (0)
    Lista* estados_a = criarListaZerada(A->tam);
    Lista* estados_b = criarListaZerada(B->tam);

    //numero de intervalos de B passados que ja comecaram e terminaram
    size_t abertos_b = 0;
    size_t fechados_b = 0;
    for(i = 0; i < C->tam; i++){
        if(C->val[i][2] == EM_B){

            size_t ib = C->val[i][1];
            
            if(estados_b->val[ib] == 0){
                //se o intervalo em questao nao comecou ainda, comeca ele
                estados_b->val[ib] = 1;
                abertos_b++;
            }
            else{
                //se ja comecou, esse e o final dele, entao fecha
                fechados_b++;
            }
        }
        else {

            size_t ia = C->val[i][1];

            if(estados_a->val[ia] == 0){
                //avisa que esse intervalo comecou
                estados_a->val[ia] = 1;
                //guarda a quantidade de fechados em B inicialmente
                contagens->val[ia] = fechados_b;
            }
            else {
                //a contagem necessariamente e a diferenca entre valores que 
                //comecaram ate o final de A[ia] menos a quantidade que ja 
                //tinha fechado depois do comeco de A[ia]
                contagens->val[ia] = abertos_b - contagens->val[ia];
            }
        }
    }

    deletarListaTuples(C);

    return contagens;
}