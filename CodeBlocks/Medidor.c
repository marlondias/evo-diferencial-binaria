///Responsável pelo calculo do tempo médio de execução do programa

#include <sys/time.h> //gettimeofday() e struct TIMEVAL
#include <inttypes.h> //int64_t
#include <stdlib.h> //NULL

#define EXECUCOES 10 //quantas execuções devem ser feitas

uint64_t tempoMedioExecucao(char* command){
    uint64_t tempoTotal = 0LL; //soma dos tempos de execução
    struct timeval startTime, endTime; //estruturas necessárias para o gettimeofday()

    for (int i=0; i<EXECUCOES; i++){
        gettimeofday(&startTime, NULL);

        ///Execução aqui
        system(command);

        gettimeofday(&endTime, NULL);
        tempoTotal += (1000000 * (endTime.tv_sec - startTime.tv_sec)) + (endTime.tv_usec - startTime.tv_usec); //(segs * 1000000) + (microsegs)
    }

    return (tempoTotal / EXECUCOES);
}
