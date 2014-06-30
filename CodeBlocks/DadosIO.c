#include <stdio.h> //file IO e prints
#include <inttypes.h>

void registrarValor(char* arquivoTxt, uint64_t numeroUsado, uint64_t tempoMicrosegs){
    //Grava o NUMERO usado e o tempo de execução do código em um arquivo de texto

    if (arquivoTxt == NULL){
        perror("Especifique um de arquivo de saida!\n");
        return;
    }

    FILE *arquivo = fopen(arquivoTxt, "a");
    if (arquivo == NULL){
        perror("Erro ao abrir arquivo de saida!\n");
        return;
    }

    fprintf(arquivo, "#: %"PRIu64" Tempo: %"PRIu64"\n", numeroUsado, tempoMicrosegs);
    printf("Resultado registrado em %s\n", arquivoTxt);

    fclose(arquivo);
}


void registrarFinal(char* arquivoTxt){
    //Adiciona uma linha especial no fim do arquivo, indicando um fechamento (usado por outras funções)

    if (arquivoTxt == NULL){
        perror("Especifique um de arquivo de saida!\n");
        return;
    }

    FILE *arquivo = fopen(arquivoTxt, "a");
    if (arquivo == NULL){
        perror("Erro ao abrir arquivo de saida!\n");
        return;
    }

    fprintf(arquivo, "---\n");

    fclose(arquivo);
}


int obterValor(char* arquivoTxt, int linhaNoTxt, uint64_t* numeroUsado, uint64_t* tempoMicrosegs){
    //Extrai o NUMERO e o TEMPO registrados no arquivo, na linha desejada

    //TBD
    //verificar se existe algo na linha (se não, retorna 0)
    //extrair o primeiro valor e colocar em NUMEROUSADO
    //extrair o segundo valor e colocar em TEMPOMICROSEGS
    return 1; //em caso de sucesso
}
