//#include <stdio.h>

#include "include/fitness.h"
#include "include/otimizacoes.h"

int main(){
    iniciaListaOtimizacoes();

    Fitness("testes/testeForLongo.c", 0xffffffff);

    return 0;
}
