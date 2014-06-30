#include <inttypes.h> //uint 64
#include <stdio.h>

#include "include/aleatorio.h"
#include "include/fitness.h"
#include "include/otimizacoes.h"

//Parametros:
#define TAM_DNA 64 //dimensão (número de variaveis dentro de cada indivíduo, genes)
#define TAM_POPULACAO 20 //número de indivíduos na população
#define TAXA_MUTACAO 0.5 //taxa de mutação
#define TAXA_PERTURBACAO 0.5 //taxa de perturbação

#define MAX_PASSAGENS 5 //quantas vezes o loop ocorre


typedef struct {
    uint64_t dna; //cada bit deste valor representa uma opção a ser ativada ou não
    uint64_t tempoExecucao; //tempo para o programa X ser executado, após utilizar o valor DNA na compilação
} individuo_t;


int verificarValidadeDoCodigo(char* codigoAlvo){
    //verificar se existe
    //verificar se pode ser compilado normalmente pelo gcc
    //retornar 0 ou 1
    return 1;
}


void gerarPopulacaoAleatoria(individuo_t individuos[], int maxIndividuos){
    for (int i=0; i<maxIndividuos; i++){
        individuos[i].dna = randomUnsignedInt64(); //coloca DNAs aleatorios nos individuos
    }
}


void calcularTempoTodos(individuo_t individuos[], int maxIndividuos, char* codigoAlvo){
    for (int i=0; i<maxIndividuos; i++){
        individuos[i].tempoExecucao = Fitness(codigoAlvo, individuos[i].dna); //manda o código e o DNA, recebe o tempo de execução
    }
}


individuo_t melhorIndividuo(individuo_t individuos[], int maxIndividuos){
    //Retorna o individuo com o menor tempo de execução
    int indiceMaisRapido = 0;
    for (int i=0; i<(maxIndividuos-1); i++){
        if (individuos[i].tempoExecucao < individuos[indiceMaisRapido].tempoExecucao){
            indiceMaisRapido = i;
        }
    }
    return individuos[indiceMaisRapido];
}


uint64_t mutacao(uint64_t dna, int geneAfetado){
    //Encontra o bit desejado dentro do valor DNA e inverte ele
    return (dna ^ (1LL << geneAfetado)); //faz uma XOR no bit desejado
}


uint64_t crossover(uint64_t dna_A, uint64_t dna_B, int geneAfetado){
    uint64_t bitMask = (1LL << geneAfetado); //Deixa o bit desejado 1 e o restante 0
    return (dna_A & ~bitMask) | (dna_B & bitMask); //Substitui o bit em A pelo bit em B
}


void EDB(char* codigoAlvo){
    int passagens = 0;

    individuo_t populacao[TAM_POPULACAO]; //abre espaço para N individuos
    gerarPopulacaoAleatoria(populacao, TAM_POPULACAO); //Gerar população inicial
    calcularTempoTodos(populacao, TAM_POPULACAO, codigoAlvo); //Fitness
    printf("Aqui2\n");

    //int parar = 0;
    while (passagens < MAX_PASSAGENS){
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

        individuo_t melhor = melhorIndividuo(populacao, TAM_POPULACAO); //Encontra o melhor indivíduo da população atual
        printf("O melhor foi: %"PRIu64" com %"PRIu64" microsegundos\n", melhor.dna, melhor.tempoExecucao);

        passagens++; //controle
    }

    //Apresentar resultados;
}


int main(){
    initSeed();
    iniciaListaOtimizacoes();

    char arquivo[30] = "testes/teste99.c";

    EDB(arquivo);

    return 0;
}
