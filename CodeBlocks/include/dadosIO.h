#ifndef DADOSIO_H_INCLUDED
#define DADOSIO_H_INCLUDED

void registrarValor(char* arquivoTxt, uint64_t numeroUsado, uint64_t tempoMicrosegs);

void registrarFinal(char* arquivoTxt);

int verificarValidadeCodigoFonte(char* nomeArquivo);

#endif // DADOSIO_H_INCLUDED
