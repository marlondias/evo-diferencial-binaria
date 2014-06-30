#include <inttypes.h> //uint 64

#include "include/aleatorio.h"

//Recebe os parametros:
#define D 64 //dimensão (número de variaveis dentro de cada indivíduo, genes)
#define N 20 //número de indivíduos na população
#define PM 0.5 //taxa de mutação
#define PR 0.5 //taxa de perturbação


typedef struct {
    uint64_t dna; //cada bit deste valor representa uma opção a ser ativada ou não
    uint64_t tempoExecucao; //tempo para o programa X ser executado, após utilizar o valor DNA na compilação
} individuo_t;

int verificarValidadeDoCodigo(char* codigoAlvo){
    //verificar se existe
    //verificar se pode ser compilado normalmente pelo gcc
    //retornar 0 ou 1
    return 0;
}

void gerarPopulacaoAleatoria(individuo_t individuos[], int maxIndividuos){
    for (int i=0; i<maxIndividuos; i++){
        individuos[i].dna = randomUnsignedInt64(); //coloca DNAs aleatorios nos individuos
    }
}

void calcularTempoDeTodos(individuo_t individuos[], int maxIndividuos, char* arquivoAlvo){
    for (int i=0; i<maxIndividuos; i++){
        individuos[i].tempoExecucao = Fitness(arquivoAlvo, individuos[i].dna); //manda o código e o DNA, recebe o tempo de execução
    }
}


void Crossover(uint64_t individuoA, uint64_t individuoB){
    //todo
    return;
}

void Mutacao(uint64_t individuo){
    //todo
    return;
}


void EDB(char* codigoAlvo, ){


    individuo populacao[N]; //abre espaço para N individuos




}



int main(){
    initSeed(); //inicia seed de aleatório
    if (verificarValidadeDoCodigo("blah.c") == 1){
        EDB(); //execute por X minutos
    }
    else {
        return 1;
    }
}
