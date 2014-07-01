#include <inttypes.h> //uint 64
#include <stdio.h>

#include "include/aleatorio.h"
#include "include/fitness.h"
#include "include/otimizacoes.h"
#include "include/dadosIO.h"

//Parametros:
#define TAM_DNA 64 //dimensão (número de variaveis dentro de cada indivíduo, genes)
#define TAM_POPULACAO 5 //número de indivíduos na população
#define TAXA_MUTACAO 0.4 //taxa de mutação
#define TAXA_PERTURBACAO 0.7 //taxa de perturbação

#define MAX_GERACOES 7 //quantas vezes o loop ocorre


typedef struct {
    uint64_t dna; //cada bit deste valor representa uma opção a ser ativada ou não
    uint64_t tempoExecucao; //tempo para o programa X ser executado, após utilizar o valor DNA na compilação
} individuo_t;


void gerarPopulacaoAleatoria(individuo_t individuos[], int maxIndividuos){
    printf("Criando população inicial...\n");
    for (int i=0; i<maxIndividuos; i++){
        individuos[i].dna = randomUnsignedInt64(); //coloca DNAs aleatorios nos individuos
        individuos[i].tempoExecucao = 0;
    }
}


void calcularTempoTodos(individuo_t individuos[], int maxIndividuos, char* codigoAlvo){
    printf("Atribuindo tempo de execução a cada indivíduo...\n");
    for (int i=0; i<maxIndividuos; i++){
        individuos[i].tempoExecucao = Fitness(codigoAlvo, individuos[i].dna); //manda o código e o DNA, recebe o tempo de execução
    }
}


individuo_t melhorIndividuo(individuo_t individuos[], int maxIndividuos){
    //Retorna o individuo com o menor tempo de execução
    int indiceMaisRapido = 0;
    for (int i=0; i<maxIndividuos; i++){
        if (individuos[i].tempoExecucao < individuos[indiceMaisRapido].tempoExecucao){
            indiceMaisRapido = i;
        }
    }
    return individuos[indiceMaisRapido];
}


uint64_t mutacao(uint64_t dna, int geneAfetado){
    //Encontra o bit desejado dentro do valor DNA e inverte ele
    //printf("Mutação aplicada no gene %d!\n", geneAfetado);
    return (dna ^ (1LL << geneAfetado)); //faz uma XOR no bit desejado
}


uint64_t crossover(uint64_t dna_A, uint64_t dna_B, int geneAfetado){
    //printf("Crossover aplicado no gene %d!\n", geneAfetado);
    uint64_t bitMask = (1LL << geneAfetado); //Deixa o bit desejado 1 e o restante 0
    return (dna_A & ~bitMask) | (dna_B & bitMask); //Substitui o bit em A pelo bit em B
}


void mostrarPopulacao(individuo_t individuos[], int maxIndividuos){
    //printf("Individuos:\n");
    for (int i=0; i<maxIndividuos; i++){
        printf("#: %"PRIx64" (%"PRIu64" us)\n", individuos[i].dna, individuos[i].tempoExecucao);
    }
    printf("\n");
}



void EDB(char* codigoAlvo){

    individuo_t melhores[MAX_GERACOES]; //cada elemento representa o melhor individuo de alguma geração
    individuo_t populacao[TAM_POPULACAO]; //abre espaço para N individuos

    gerarPopulacaoAleatoria(populacao, TAM_POPULACAO); //Gerar população inicial
    calcularTempoTodos(populacao, TAM_POPULACAO, codigoAlvo); //Fitness

    int geracao = 0; //conta quantas gerações se passaram (loops)
    printf("\nIniciando com a população:\n");
    mostrarPopulacao(populacao, TAM_POPULACAO);
    melhores[0] = melhorIndividuo(populacao, TAM_POPULACAO); //guarda o melhor da população aleatória

    int parar = 0; //parada de emergencia
    while ((geracao < MAX_GERACOES) && (!parar)){
        geracao++;

        for (int indexPop=0; indexPop<TAM_POPULACAO; indexPop++){
            int indexParceiro = randomInt_RangeExceto(0, TAM_POPULACAO, indexPop); //Indice de um indivíduo aleatorio, que nao seja o atual
            int indexGeneAleatorio = randomInt_Range(0, TAM_DNA); //Indice aleatorio de um gene

            individuo_t clone; //individuo teste recebe o atual
            clone.dna = populacao[indexPop].dna;
            clone.tempoExecucao = populacao[indexPop].tempoExecucao;

            for (int indexGene=0; indexGene<TAM_DNA; indexGene++){
                if ((randomReal_Range(0,1) < TAXA_PERTURBACAO) || (indexGene == indexGeneAleatorio)){
                    //Haverá perturbação nesse gene
                    if (randomReal_Range(0,1) < TAXA_MUTACAO){
                        //A perturbação será uma MUTAÇÂO
                        clone.dna = mutacao(clone.dna, indexGene); //inverte o gene atual
                    }
                    else {
                        //A perturbação será um CROSSOVER
                        clone.dna = crossover(clone.dna, populacao[indexParceiro].dna, indexGene); //recebe um gene do parceiro
                    }
                }
            }

            clone.tempoExecucao = Fitness(codigoAlvo, clone.dna); //Calcula o fitness do individuo teste

            if (clone.tempoExecucao < populacao[indexPop].tempoExecucao){
                //Se o clone ficou melhor que o original, o clone entra na população (substituindo o original)
                populacao[indexPop].dna = clone.dna;
                populacao[indexPop].tempoExecucao = clone.tempoExecucao;
            }
        }

        melhores[geracao] = melhorIndividuo(populacao, TAM_POPULACAO); //Encontra o melhor indivíduo da população atual

        printf("População %d:\n", geracao);
        mostrarPopulacao(populacao, TAM_POPULACAO);
        printf("Melhor indivíduo: %"PRIx64"\n\n", melhores[geracao].dna);

    }

    printf("Os melhores foram:\n");
    mostrarPopulacao(melhores, MAX_GERACOES); //Apresentar resultados
}


int main(){
    char codigoFonte[] = "testes/testeForLongo.c";

    if (verificarValidadeCodigoFonte(codigoFonte) == 0){
        printf("Código fonte inválido!\n");
        return 1;
    }

    initSeed();
    iniciaListaOtimizacoes();

    EDB(codigoFonte);
    return 0;
}
