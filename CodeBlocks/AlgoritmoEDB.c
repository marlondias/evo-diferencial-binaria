#include <inttypes.h> //uint 64

#include "include/aleatorio.h"

#define bit_full FFFFFFFFFFFFFFFF//todos os bits são 1
#define bit_zeros 0000000000000000//todos os bits são 0


//Recebe os parametros:
#define D 64 //dimensão (variaveis do elemento)
#define N 20 //número de indivíduos
#define PM 0.5 //taxa de mutação
#define PR 0.5 //taxa de perturbação






void Crossover(uint64_t individuoA, uint64_t individuoB){
    //todo
    return;
}

void Mutacao(uint64_t individuo){
    //todo
    return;
}

int Fit(uint64_t individuo){
    //todo
    return 33;
}

void FitTodos(uint64_t individuos[]){
    //todo
    return;
}


void EDB() {

    ///Gera população inicial com N indivíduos aleatorios
    uint64_t individuos[N];
    for (int a=0; a<N; a++){
        individuos[a] = randomUnsignedInt64();
    }


    ///calcular FITNESS de cada individuo -- falta


    int parar = 0;
    while (!parar) {

        for (int i=0; i<N; i++){ //passa por cada individuo

            int s = randomInt_RangeExceto(0, N-1, i); //escolhe um individuo qualquer, que não seja o atual


            ///escolha aleatoriamente o indice de uma variavel (bit): j[rand] = rndint(1,D)
            int bit = randomInt_Range(0, D-1); //escolhe aleatoriamente um dos bits (0 a 63)
            //Wut??


            uint64_t indivTeste = individuos[i]; //solução teste y recebe x[i]

            for (int j=0; j<D; j++) {
                if ((randomReal_Range(0, 1) < PR) || (0 /* j == j[rand] */)){ //perturbação de y
                    if (randomReal_Range(0, 1) < PM){ //mutação
                        //InverterBit()
                    }
                    else { //crossover
                        //y[j] = x[sj] -- ??
                    }
                }
            }

            ///Calcular fitness de y -- será calculado no proximo IF

            if (Fit(indivTeste) > Fit(individuos[i])){
                individuos[i] = indivTeste; //atualiza solução corrente
            }
        }

        ///encontrar melhor solução corrente de x[]
    }

    ///apresentar resultados

}
