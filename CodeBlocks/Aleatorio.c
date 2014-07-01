///Funções de geração de números e coisas relacionadas

#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

void initSeed(){
    srand(time(NULL)); //usa o tempo atual como seed para gerar os números aleatórios
}

uint64_t randomUnsignedInt64(){
    uint64_t result = rand(); //recebe um valor de 32 bits
    result = result << 32; //abre espaço para outros 32 bits
    result |= rand(); //preenche a outra metade do valor
    return result;
}

int randomInt_Range(int min, int max){
    //Retorna um valor entre MIN e MAX (inclusivo)
    //Não funciona com valores negativos

    if (min > max) return min; //usuario burro..
    if (min == max) return min;

    int maiorBit = 0; //receberá bit mais significativo de MAX
    int aux = max;
    while (aux != 0){
        aux = aux >> 1;
        if (maiorBit == 0) maiorBit = 1;
        else maiorBit = maiorBit << 1;
    }
    maiorBit = (maiorBit << 1) - 1; //a variavel se torna uma mascara de bits

    int numero;
    while (1){
        numero = rand() & maiorBit;
        if ((numero >= min) && (numero <= max)) return numero;
    }
}

int randomInt_RangeExceto(int min, int max, int excluido){
    //Retona um numero entre MIN e MAX (inclusivo) que seja diferente de EXCLUIDO
    //Não funciona com valores negativos

    if (min > max) return min; //usuario burro..
    if (min == max) return min;

    int maiorBit = 0; //receberá bit mais significativo de MAX
    int aux = max;
    while (aux != 0){
        aux = aux >> 1;
        if (maiorBit == 0) maiorBit = 1;
        else maiorBit = maiorBit << 1;
    }
    maiorBit = (maiorBit << 1) - 1; //a variavel se torna uma mascara de bits

    int numero;
    while (1){
        numero = rand() & maiorBit;
        if ((numero >= min) && (numero <= max) && (numero != excluido)) return numero;
    }
}

float randomReal_Range(float min, float max){
    //Retorna um número real entre MIN e MAX (inclusivo)

    int divisor = 0;
    while (divisor == 0){ //evita divisão por zero
        divisor = rand();
    }

    float numero;
    while (1){
        numero = (float)rand() / divisor;
        if ((numero >= min) && (numero <= max)) return numero;
    }
}


