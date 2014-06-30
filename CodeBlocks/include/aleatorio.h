#ifndef ALEATORIO_H_INCLUDED
#define ALEATORIO_H_INCLUDED

void initSeed();

uint64_t randomUnsignedInt64();

int randomInt_Range(int minimo, int maximo);

int randomInt_RangeExceto(int minimo, int maximo, int excluido);

float randomReal_Range(float minimo, float maximo);

#endif // ALEATORIO_H_INCLUDED
