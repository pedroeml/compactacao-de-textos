#include <stdio.h>
#include <stdlib.h>
#include "ListaDePalavras.h"
#include "TextoComoListaDePalavras.h"

FILE* AbreArquivo(const char *nome, const char *tipoArquivo) {
    FILE *arq;
    arq = fopen (nome,tipoArquivo);
    if (arq == NULL) {
        system("clear");
        printf("Problemas na abertura do arquivo %s...\n", nome);
        return NULL;
    }
    system("clear");
    printf("Arquivo %s aberto!\n", nome);
    return arq;
}


void LeDadosTXT(FILE *arq) {
    char *palavra;
    while(!feof(arq)){
        palavra = (char *) malloc(sizeof(char)*32); // Permite que a palavra tenha até 31 caracteres
        fscanf(arq, "%s", palavra);
        addNodoCOMREP(palavra);
    }
    printf("\n");
}

void LeCabecalhoBin(FILE *arq, int *sizeListSEMREP, int *sizeListCOMREP) {
    int aux;
    fread(&aux, sizeof(int), 1, arq);
    *sizeListSEMREP = aux;
    fread(&aux, sizeof(int), 1, arq);
    *sizeListCOMREP = aux;
    printf("Cabeçalho: sizeListaSEMREP = %d, sizeListaCOMREP = %d\n", *sizeListSEMREP, *sizeListCOMREP);
}

void LeDadosBin(FILE *arq, int size) {
   int i;
   char *palavra;
   //char palavra[32];
   for (i=0;i<size;i++) {
       //char *palavra;
       palavra = (char *) malloc(sizeof(char)*32); // aloco espaço para a palavra
       fread(&palavra, (sizeof(char)*32), 1, arq); // armazeno a palavra lida na string
       printf("%s ", palavra);
       //free(palavra); // desaloco espaço para o próximo passo da repetição usar espaço novo e livre e não ficar o lixo da repetição anterior solto
    }
    printf("\n");
}

void GravaListaSEMREPBinario(FILE *arq, int size) {
    NodoSEMREP *ptr;
    int result, i;
    char *palavra;

    ptr = getInicioSEMREP();

    printf("Gravando ListaSEMREP no arquivo\nGravou as palavras:\n");

    for (i = 0; i<size; i++) {
        palavra = ptr->palavra;
        printf("\"%s\", ", palavra);
        result = fwrite(&palavra, (sizeof(char)*32), 1, arq); //endereço da palavra, número de caracteres da palavra, quantidade de vezes, arquivo
        ptr = ptr->prox;
    }
    printf("\n\n");
}

void GravaListaCOMREPBinario(FILE *arq, int size) {
    NodoCOMREP *ptr;
    int result, i;
    char *palavra;

    ptr = getInicioCOMREP();

    printf("Gravando ListaCOMREP no arquivo\nGravou as palavras:\n");

    for(i = 0; i<size; i++) {
        palavra = ptr->nodo->palavra;
        printf("\"%s\", ", palavra);
        result = fwrite(&palavra, (sizeof(char)*32), 1, arq); //endereço da palavra, número de caracteres da palavra, quantidade de vezes, arquivo
        ptr = ptr->prox;
    }
    printf("\n\n");
}

void GravaArquivoBinario() {
    FILE *arq;

    int result, sizeListSEMREP, sizeListCOMREP;
    sizeListSEMREP = sizeListaSEMREP();
    sizeListCOMREP = sizeListaCOMREP();
    arq = fopen("files/ArquivoBinario.dat", "wb");

    if (arq == NULL) {
        printf("Problemas na criação do arquivo\n");
        return;
    }

    result = fwrite(&sizeListSEMREP, sizeof(int), 1, arq);
    printf("Gravou como cabeçalho o tamanho ListaSEMREP: %d\n", sizeListSEMREP);
    result = fwrite(&sizeListCOMREP, sizeof(int), 1, arq);
    printf("Gravou como cabeçalho o tamanho ListaCOMREP: %d\n", sizeListCOMREP);
    GravaListaSEMREPBinario(arq, sizeListSEMREP);
    GravaListaCOMREPBinario(arq, sizeListCOMREP);
    fclose(arq);
}
