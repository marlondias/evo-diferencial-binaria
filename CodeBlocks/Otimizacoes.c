/** Aqui está definido um vetor de strings. Cada elemento representa uma otimização aceita pelo GCC.
    Estas informações foram encontradas em: http://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
    Se necessário, basta alterar estes valores ou adicionar novos. **/

const char *otimizacoes[256]; //um vetor com 256 flags de otimizações (do GCC)

void iniciaListaOtimizacoes(){
    //Ativadas pela opção -o1
    otimizacoes[0] = " -fauto-inc-dec";
    otimizacoes[1] = " -fcompare-elim";
    otimizacoes[2] = " -fcprop-registers";
    otimizacoes[3] = " -fdce";
    otimizacoes[4] = " -fdefer-pop";
    otimizacoes[5] = " -fdelayed-branch";
    otimizacoes[6] = " -fdse";
    otimizacoes[7] = " -fguess-branch-probability";
    otimizacoes[8] = " -fif-conversion2";
    otimizacoes[9] = " -fif-conversion";
    otimizacoes[10] = " -fipa-pure-const";
    otimizacoes[11] = " -fipa-profile";
    otimizacoes[12] = " -fipa-reference";
    otimizacoes[13] = " -fmerge-constants";
    otimizacoes[14] = " -fsplit-wide-types";
    otimizacoes[15] = " -ftree-bit-ccp";
    otimizacoes[16] = " -ftree-builtin-call-dce";
    otimizacoes[17] = " -ftree-ccp";
    otimizacoes[18] = " -ftree-ch";
    otimizacoes[19] = " -ftree-copyrename";
    otimizacoes[20] = " -ftree-dce";
    otimizacoes[21] = " -ftree-dominator-opts";
    otimizacoes[22] = " -ftree-dse";
    otimizacoes[23] = " -ftree-forwprop";
    otimizacoes[24] = " -ftree-fre";
    otimizacoes[25] = " -ftree-phiprop";
    otimizacoes[26] = " -ftree-slsr";
    otimizacoes[27] = " -ftree-sra";
    otimizacoes[28] = " -ftree-pta";
    otimizacoes[29] = " -ftree-ter";
    otimizacoes[30] = " -funit-at-a-time";
    otimizacoes[31] = " -fomit-frame-pointer"; //on machines where doing so does not interfere with debugging (??)

    //Ativadas por -o2
    otimizacoes[32] = " -fthread-jumps";
    otimizacoes[33] = " -falign-functions";
    otimizacoes[34] = " -falign-jumps";
    otimizacoes[35] = " -falign-loops";
    otimizacoes[36] = " -falign-labels";
    otimizacoes[37] = " -fcaller-saves";
    otimizacoes[38] = " -fcrossjumping";
    otimizacoes[39] = " -fcse-follow-jumps";
    otimizacoes[40] = " -fcse-skip-blocks";
    otimizacoes[41] = " -fdelete-null-pointer-checks";
    otimizacoes[42] = " -fdevirtualize";
    otimizacoes[43] = " -fdevirtualize-speculatively";
    otimizacoes[44] = " -fexpensive-optimizations";
    otimizacoes[45] = " -fgcse"; //warning on programs that use computed gotos (??)
    otimizacoes[46] = " -fgcse-lm";
    otimizacoes[47] = " -fhoist-adjacent-loads";
    otimizacoes[48] = " -finline-small-functions";
    otimizacoes[49] = " -findirect-inlining";
    otimizacoes[50] = " -fipa-sra";
    otimizacoes[51] = " -fisolate-erroneous-paths-dereference";
    otimizacoes[52] = " -foptimize-sibling-calls";
    otimizacoes[53] = " -fpartial-inlining";
    otimizacoes[54] = " -fpeephole2";
    otimizacoes[55] = " -freorder-blocks";
    otimizacoes[56] = " -freorder-functions";
    otimizacoes[57] = " -frerun-cse-after-loop";
    otimizacoes[58] = " -fsched-interblock";
    otimizacoes[59] = " -fsched-spec";
    otimizacoes[60] = " -fschedule-insns";
    otimizacoes[61] = " -fschedule-insns2";
    otimizacoes[62] = " -fstrict-aliasing";
    otimizacoes[63] = " -fstrict-overflow";
    otimizacoes[64] = " -ftree-switch-conversion";
    otimizacoes[64] = " -ftree-tail-merge";
    otimizacoes[66] = " -ftree-pre";
    otimizacoes[67] = " -ftree-vrp";

    //Ativadas por -o3
    otimizacoes[68] = " -finline-functions";
    otimizacoes[69] = " -funswitch-loops";
    otimizacoes[70] = " -fpredictive-commoning";
    otimizacoes[71] = " -fgcse-after-reload";
    otimizacoes[72] = " -ftree-loop-vectorize";
    otimizacoes[73] = " -ftree-slp-vectorize";
    otimizacoes[74] = " -fvect-cost-model";
    otimizacoes[75] = " -ftree-partial-pre";
    otimizacoes[76] = " -fipa-cp-clone";

    //Outras...

}
