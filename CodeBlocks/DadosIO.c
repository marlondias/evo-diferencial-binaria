#include <stdio.h> //file IO e prints
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>


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


int verificarValidadeCodigoFonte(char* nomeArquivo){
    const char* prefixo = "gcc -o testes/binVerificacao -std=c99 ";

    char* comando = malloc(strlen(prefixo) + strlen(nomeArquivo) + 1);
    if (comando != NULL){
        strcpy(comando, prefixo);
        strcat(comando, nomeArquivo);
    }
    else {
        return 0; //não tem memoria disponivel, melhor parar
    }

    int saida = system(comando);
    if (saida != 0){
        return 0; //não foi possivel compilar
    }

    return 1;
}
