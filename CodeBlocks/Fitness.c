#include <stdlib.h> //system() e malloc()
#include <inttypes.h> //uint64
#include <string.h> //strcat()

#include "include/otimizacoes.h"
#include "include/medidor.h"


char* join(const char* s1, const char* s2){ //cortesia stackoverflow
    char* result = malloc(strlen(s1) + strlen(s2) + 1);

    if (result != NULL){
        strcpy(result, s1);
        strcat(result, s2);
    }

    return result;
}


void AplicarOtim(uint64_t numero, char* strRetorno){ //retirar
/*  Verifica todos os bits em NUMERO. Se algum bit for 1, a otimização correspondente será aplicada.
    Esta função analisa um conjunto de 64 otimizações, pertencentes ao vetor definido em "otimizacoes.c".
    STRRETORNO é uma string contendo todas as flags que devem ser aplicadas ao GCC (com os espaços corretos). */

    uint64_t bit = 1; //usado para comparação dos bits
    for (int posicao=0; posicao<64; posicao++){
        if (numero & bit){ //se o bit na posição X for igual a 1, aplica a otimização X
            join(strRetorno, otimizacoes[posicao]);
        }
        bit = bit << 1; //desloca o bit para a esquerda e repete
    }
    return;
}


uint64_t Fitness(char* nomePrograma, uint64_t numero){
    ///Retorna o valor do tempo de execução

    const char* inicio = "gcc -o testes/testBin ";
    char* paramOpcionais = "-std=c99 ";


    //Relaciona o NUMERO com as otimizações..
    char* listaOtimiz = "";
    uint64_t bit = 1; //usado para comparar bit a bit
    for (int pos=0; pos<64; pos++){
        if (numero & bit){
            //se o bit na posição é 1, aplica a otimização correspondente
            listaOtimiz = join(listaOtimiz, otimizacoes[pos]);
        }
        bit = bit << 1; //desloca o bit para a esquerda e repete
    }


    //Aloca dinamicamente o espaço necessário e concatena as partes para formar um comando de compilação
    char* comando = malloc(strlen(inicio) + strlen(paramOpcionais) + strlen(listaOtimiz) + strlen(nomePrograma) + 1);
    strcat(comando, inicio);
    strcat(comando, paramOpcionais);
    strcat(comando, listaOtimiz);
    strcat(comando, nomePrograma);


    //Envia o comando e faz a compilação
    system(comando);
    free(comando);
    //falta verificar as saidas do GCC


    //Executa o programa e obtém o tempo médio de execução
    uint64_t tempoMicrosegs = tempoMedioExecucao("./testes/testBin");

    return tempoMicrosegs;
}
