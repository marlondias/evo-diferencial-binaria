#include <sys/time.h> //gettimeofday()
#include <stdlib.h> //system()
#include <inttypes.h> //uint64
#include <string.h> //strcat()
#include "otimizacoes.h"

#include <stdio.h>


const char* AplicarOtim(uint64_t numero, int deslocamento){
/** Verifica todos os bits em NUMERO. Se algum bit for 1, a otimização correspondente será aplicada.
    Esta função analisa um conjunto de 64 otimizações, pertencentes ao vetor definido em "otimizacoes.c".
    O retorno é uma string contendo todas as flags que devem ser aplicadas ao GCC (com os espaços corretos).
    Obs:
      deslocamento = 0 --> Otimizações 0 a 63
      deslocamento = 64 --> Otimizações 64 a 127
      deslocamento = 128 --> Otimizações 128 a 191... **/

    char flagOtimiz[2000] = ""; //Receberá as flags que devem ser aplicadas e será retornada nos argumentos da função

    uint64_t bit = 1; //apenas o bit menos significativo

    for (int posicao=0; posicao<64; posicao++){
        if (numero & bit){
            //se o bit na posição X for igual a 1, aplica a otimização X
            strcat(flagOtimiz, otimizacoes[posicao+deslocamento]);
        }
        bit = bit << 1; //desloca o bit para a esquerda e repete
    }

    const char *retorno = flagOtimiz;
    return retorno;
}


void Fitness(uint64_t numero, char* nomePrograma){

    ///Inicia a montagem do comando de compilação
    char comando[3000] = "gcc"; //se for maior que 3000 faz favor né
    strcat(comando, " -std=c99"); //opcional

    printf("%s\n", comando);

    ///Relaciona o NUMERO com as otimizações..
    strcat(comando, AplicarOtim(numero, 0));

    printf("%s\n", comando);

    ///Fecha com o nome do programa
    strcat(comando, " ");
    strcat(comando, nomePrograma);

    printf("%s\n", comando);

    ///Envia o comando e faz a compilação
    //system(comando); //gera um "a.out"
    //falta verificar erro

    ///Executa o programa e obtém o tempo de execução (em microsegundos)
    struct timeval inicio, parada;
    uint64_t tempoMicrosegs;
    gettimeofday(&inicio, NULL);
    //system("./a.out"); //Execução aqui
    gettimeofday(&parada, NULL);
    tempoMicrosegs = (1000000 * (parada.tv_sec - inicio.tv_sec)) + (parada.tv_usec - inicio.tv_usec);

    ///Grava o NUMERO usado e o tempo de execução do código
    //aqui entra o YAML?
    printf("Número: %ld -- Tempo: %ld microsegundos\n", numero, tempoMicrosegs); //teste

    return; //fim
}
