#include <stdio.h>
#include <stdlib.h>
#include "RWFile.h"
#include "ListaDePalavras.h"
#include "TextoComoListaDePalavras.h"

int opcao1() {
    FILE *Arquivo;
    char *s;
    printf("Digite o nome do arquivo que deseja ler:\n");
    s = (char *) malloc(sizeof(char)*32);
    scanf("%s", s);

    Arquivo = AbreArquivo(s, "rt");

    if (!Arquivo)
        return 1;

    inicializaListaDePalavras();
    inicializaTextoComoListaDePalavras();
    LeDadosTXT(Arquivo);
    printListaSEMREP();
    printf("Tamanho da ListaSEMREP: %d\n", sizeListaSEMREP());
    printListaCOMREP();
    printf("Tamanho da ListaCOMREP: %d\n", sizeListaCOMREP());
    GravaArquivoBinario();
    esvaziaListaSEMREP();
    esvaziaListaCOMREP();
    free(s);
    return -1;
}

int opcao2() {
    FILE *Arquivo;
    char *s;
    printf("Digite o nome do arquivo que deseja ler:\n");
    s = (char *) malloc(sizeof(char)*32);
    scanf("%s", s);

    Arquivo = AbreArquivo(s, "rb");

    if (!Arquivo)
        return 1;
    int sizeListSEMREP, sizeListCOMREP;
    LeCabecalhoBin(Arquivo, &sizeListSEMREP, &sizeListCOMREP);
    LeDadosBin(Arquivo, sizeListSEMREP);
    LeDadosBin(Arquivo, sizeListCOMREP);
    free(s);
    return -1;
}

int main() {
    int input = -1, *in;
    while(input != 0) {
        in = (int *) malloc(sizeof(int));

        printf("[1] - Ler arquivo texto, gerar estruturas e gravar seus dados em arquivo binário\n");
        printf("[2] - Ler arquivo binário gerado pela opção anterior e exibir resultados\n");
        printf("[0] - Encerrar programa\n\n>>");
        scanf("%d", in);

        input = *in;

        switch (input) {
            case 1: system("clear");
                    input = opcao1();
                    free(in);
                    break;
            case 2: system("clear");
                    input = opcao2();
                    free(in);
                    break;
            default:system("clear");
                    printf("\n\nEXECUÇÃO CONCLUÍDA\n");
                    free(in);
                    return 0;
        }
    }
    return 0;
}
