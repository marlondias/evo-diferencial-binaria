#include <stdlib.h> //system()
#include <inttypes.h> //uint64
#include <string.h> //strcat()

#include "include/otimizacoes.h"
#include "include/medidor.h"
#include "include/dadosIO.h"


void AplicarOtim(uint64_t numero, char strRetorno[2000]){
/*  Verifica todos os bits em NUMERO. Se algum bit for 1, a otimização correspondente será aplicada.
    Esta função analisa um conjunto de 64 otimizações, pertencentes ao vetor definido em "otimizacoes.c".
    STRRETORNO é uma string contendo todas as flags que devem ser aplicadas ao GCC (com os espaços corretos). */

    uint64_t bit = 1; //usado para comparação dos bits
    for (int posicao=0; posicao<64; posicao++){
        if (numero & bit){ //se o bit na posição X for igual a 1, aplica a otimização X
            strcat(strRetorno, otimizacoes[posicao]);
        }
        bit = bit << 1; //desloca o bit para a esquerda e repete
    }
    return;
}


void FitnessTxt(char* nomePrograma, uint64_t numero){
    //Fitness que guarda os valores em texto

    ///Inicia a montagem do comando de compilação (pelo GCC)
    char comando[3000] = "gcc"; //se for maior que 3000 faz favor né
    strcat(comando, " -std=c99"); //opcional


    ///Relaciona o NUMERO com as otimizações..
    char flagOtimiz[2000]; //recebe a lista de otimizações
    AplicarOtim(numero, flagOtimiz);
    strcat(comando, flagOtimiz); //concatena com o inicio do comando


    ///Fecha com o nome da saida e o nome do programa..
    strcat(comando, " -o testes/fitnessBin ");
    strcat(comando, nomePrograma);


    ///Envia o comando e faz a compilação
    int saidaGCC = system(comando); //gera um binario "fitnessBin"
    //printf("Comando: %s \nSaida: %d\n", comando, saidaGCC);
    //falta verificar as saidas do GCC


    ///Executa o programa e obtém o tempo médio de execução
    uint64_t tempoMicrosegs = tempoMedioExecucao("./testes/fitnessBin");

    if (saidaGCC != 0){
        //O arquivo binário não foi gerado pelo NUMERO atual (é da compilação anterior ou ainda não existe).
        //Portanto, será aplicada uma penalidade (% do tempo) ao tempo obtido.

        //falta considerar o caso onde o binario não existe
        //pois o tempo de execução será MUITO menor que os outros, mesmo com a penalidade
    }


    ///Registra os valores
    registrarValor("testes/result.txt", numero, tempoMicrosegs);

    return; //fim
}


uint64_t Fitness(char* nomePrograma, uint64_t numero){
    ///Fitness que devolve o valor no retorno da função

    //Inicia a montagem do comando de compilação (pelo GCC)
    char comando[3000] = "gcc"; //se for maior que 3000 faz favor né
    strcat(comando, " -std=c99"); //opcional


    //Relaciona o NUMERO com as otimizações..
    char flagOtimiz[2000]; //recebe a lista de otimizações
    AplicarOtim(numero, flagOtimiz);
    strcat(comando, flagOtimiz); //concatena com o inicio do comando


    //Fecha com o nome da saida e o nome do programa..
    strcat(comando, " -o testes/fitnessBin ");
    strcat(comando, nomePrograma);


    //Envia o comando e faz a compilação
    int saidaGCC = system(comando); //gera um binario "fitnessBin"
    //falta verificar as saidas do GCC


    //Executa o programa e obtém o tempo médio de execução
    uint64_t tempoMicrosegs = tempoMedioExecucao("./testes/fitnessBin");

    if (saidaGCC != 0){
        //O arquivo binário não foi gerado pelo NUMERO atual (é da compilação anterior ou ainda não existe).
        //Portanto, será aplicada uma penalidade (% do tempo) ao tempo obtido.

        //falta considerar o caso onde o binario não existe
        //pois o tempo de execução será MUITO menor que os outros, mesmo com a penalidade
    }


    return tempoMicrosegs;
}
