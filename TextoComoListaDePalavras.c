#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListaDePalavras.h"
#include "TextoComoListaDePalavras.h"

NodoCOMREP *inicioCOMREP;

void inicializaTextoComoListaDePalavras() {
    inicioCOMREP = NULL;
}

/** Função que cria um nodo com a descrição definida na linha 14-17 de nodos para a lista com repetição.
 *  Retorno: referência para o nodo criado no escopo da função.
 */
NodoCOMREP* criaNodoCOMREP(char *palavra) {
    NodoCOMREP *nodo;

    nodo = (NodoCOMREP *) malloc(sizeof(NodoCOMREP));

    if (nodo == NULL) {
        printf("Erro de alocação\n");
        return NULL;
    }

    nodo->nodo = addNodoSEMREP(palavra); // Esta atribuição depende do que esta função retornar
    nodo->prox = NULL;

    return nodo;
}

/** Função que adiciona um nodo na lista com repetição.
 */
void addNodoCOMREP(char *palavra) {
    NodoCOMREP *ptr;

    if(inicioCOMREP != NULL) { // Se a lista não estiver vazia
        ptr = inicioCOMREP; // O ponteiro aponta para o início da lista
        while (ptr->prox != NULL) // Iteramos a lista até o último nodo
            ptr = ptr->prox;
        ptr->prox = criaNodoCOMREP(palavra); // No último nodo definimos o seu seguinte o nodo criado por esta função
    }
    else
        inicioCOMREP = criaNodoCOMREP(palavra); // Se a lista estiver vazia o seu primeiro nodo é o retornado por esta função
}

void printListaCOMREP() {
    NodoCOMREP *ptrCOMREP;

    if (inicioCOMREP == NULL) {
        printf("LISTA COM REPETIÇÃO VAZIA\n\n");
        return;
    }
    printf("LISTA COM REPETIÇÃO:\n");

    ptrCOMREP = inicioCOMREP;

    while (ptrCOMREP != NULL) {
        printf("\"%s\", ", ptrCOMREP->nodo->palavra);
        ptrCOMREP = ptrCOMREP->prox;
    }

    printf("\n\n");
}

void esvaziaListaCOMREP() {
    NodoCOMREP *aux, *temp;
    aux = inicioCOMREP;
    while (aux != NULL) {
        temp = aux->prox;
        free(aux); // Libera a memória alocada para o nodo
        aux = temp;
    }
    inicioCOMREP = NULL;
}

int sizeListaCOMREP() {
    int size = 0;
    NodoCOMREP *aux;
    aux = inicioCOMREP;
    while(aux != NULL) {
        size++;
        aux = aux->prox;
    }
    return size-1; // Por conta da última linha do arquivo ser vazia, é criado um nodo a mais.
}

NodoCOMREP* getInicioCOMREP() {
    return inicioCOMREP;
}
