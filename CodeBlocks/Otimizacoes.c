/** Aqui está definido um vetor de strings. Cada elemento representa uma otimização aceita pelo GCC.
    Estas informações foram encontradas em: http://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
    Se necessário, basta alterar estes valores ou adicionar novos.

    Obs: Cada flag deve terminar em espaço **/

#include <stdio.h>
#define MAX_OTIMIZACOES 128


const char *otimizacoes[MAX_OTIMIZACOES]; //um vetor com 256 flags de otimizações (do GCC)

void iniciaListaOtimizacoes(){
    //Ativadas pela opção -o1
    otimizacoes[0] = "-fauto-inc-dec ";
    otimizacoes[1] = "-fcompare-elim ";
    otimizacoes[2] = "-fcprop-registers ";
    otimizacoes[3] = "-fdce ";
    otimizacoes[4] = "-fdefer-pop ";
    otimizacoes[5] = "-fdelayed-branch ";
    otimizacoes[6] = "-fdse ";
    otimizacoes[7] = "-fguess-branch-probability ";
    otimizacoes[8] = "-fif-conversion ";
    otimizacoes[9] = "-fif-conversion2 ";
    otimizacoes[10] = "-fipa-pure-const ";
    otimizacoes[11] = "-fipa-profile ";
    otimizacoes[12] = "-fipa-reference ";
    otimizacoes[13] = "-fmerge-constants ";
    otimizacoes[14] = "-fsplit-wide-types ";
    otimizacoes[15] = "-ftree-bit-ccp ";
    otimizacoes[16] = "-ftree-builtin-call-dce ";
    otimizacoes[17] = "-ftree-ccp ";
    otimizacoes[18] = "-ftree-ch ";
    otimizacoes[19] = "-ftree-copyrename ";
    otimizacoes[20] = "-ftree-dce ";
    otimizacoes[21] = "-ftree-dominator-opts ";
    otimizacoes[22] = "-ftree-dse ";
    otimizacoes[23] = "-ftree-forwprop ";
    otimizacoes[24] = "-ftree-fre ";
    otimizacoes[25] = "-ftree-phiprop ";
    otimizacoes[26] = "-ftree-slsr ";
    otimizacoes[27] = "-ftree-sra ";
    otimizacoes[28] = "-ftree-pta ";
    otimizacoes[29] = "-ftree-ter ";
    otimizacoes[30] = "-funit-at-a-time ";
    otimizacoes[31] = "-fomit-frame-pointer "; //on machines where doing so does not interfere with debugging (??)

    //Ativadas por -o2
    otimizacoes[32] = "-fthread-jumps ";
    otimizacoes[33] = "-falign-functions ";
    otimizacoes[34] = "-falign-jumps ";
    otimizacoes[35] = "-falign-loops ";
    otimizacoes[36] = "-falign-labels ";
    otimizacoes[37] = "-fcaller-saves ";
    otimizacoes[38] = "-fcrossjumping ";
    otimizacoes[39] = "-fcse-follow-jumps ";
    otimizacoes[40] = "-fcse-skip-blocks ";
    otimizacoes[41] = "-fdelete-null-pointer-checks ";
    otimizacoes[42] = "-fdevirtualize ";
    otimizacoes[43] = "-fexpensive-optimizations ";
    otimizacoes[44] = "-fgcse "; //warning on programs that use computed gotos (??)
    otimizacoes[45] = "-fgcse-lm ";
    otimizacoes[46] = "-fhoist-adjacent-loads ";
    otimizacoes[47] = "-finline-small-functions ";
    otimizacoes[48] = "-findirect-inlining ";
    otimizacoes[49] = "-fipa-sra ";
    otimizacoes[50] = "-foptimize-sibling-calls ";
    otimizacoes[51] = "-fpartial-inlining ";
    otimizacoes[52] = "-fpeephole2 ";
    otimizacoes[53] = "-freorder-blocks ";
    otimizacoes[54] = "-freorder-functions ";
    otimizacoes[55] = "-frerun-cse-after-loop ";
    otimizacoes[56] = "-fsched-interblock ";
    otimizacoes[57] = "-fsched-spec ";
    otimizacoes[58] = "-fschedule-insns ";
    otimizacoes[59] = "-fschedule-insns2 ";
    otimizacoes[60] = "-fstrict-aliasing ";
    otimizacoes[61] = "-fstrict-overflow ";
    otimizacoes[62] = "-ftree-switch-conversion ";
    otimizacoes[63] = "-ftree-tail-merge ";
    otimizacoes[64] = "-ftree-pre ";
    otimizacoes[65] = "-ftree-vrp ";

    //Ativadas por -o3
    otimizacoes[66] = "-finline-functions ";
    otimizacoes[67] = "-funswitch-loops ";
    otimizacoes[68] = "-fpredictive-commoning ";
    otimizacoes[69] = "-fgcse-after-reload ";
    otimizacoes[70] = "-ftree-loop-vectorize ";

    otimizacoes[71] = "-fvect-cost-model ";
    otimizacoes[72] = "-ftree-partial-pre ";
    otimizacoes[73] = "-fipa-cp-clone ";

    //Outras...
    for (int i=74; i<MAX_OTIMIZACOES; i++){
        otimizacoes[i] = " "; //evitando NULLs
    }

    return;
}

void MostraOtimizacoes(){
    printf("Otimizações disponíveis:\n");
    for (int num = 0; num < MAX_OTIMIZACOES; num++){
        printf("%d -- %s\n", num, otimizacoes[num]);
    }
}
