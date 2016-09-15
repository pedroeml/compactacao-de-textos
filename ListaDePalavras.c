#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListaDePalavras.h"

NodoSEMREP *inicioSEMREP;

void inicializaListaDePalavras() {
    inicioSEMREP = NULL;
}

/** Função que itera a lista sem repetição por completa procurando pela palavra em parâmetro.
 *  Retorno: NULL, se não encontrar a palavra ao terminar a iteração ou a lista estiver vazia.
 *           Referência para o nodo que possui a palavra em parâmetro.
 */
NodoSEMREP* existePlavraNaLista(char *palavra) {
    NodoSEMREP *ptr;

    if (inicioSEMREP == NULL)
        return NULL;

    ptr = inicioSEMREP;

    while (ptr != NULL) {
        char *s; // Crio um ponteiro para a palavra do nodo auxiliar que no momento
        s = ptr->palavra; // esta apontando para a palavra do nodo do inicio da lista
        if (strcmp(s, palavra) == 0) // Comparo se esta palavra é igual a que recebemos por parâmetro
            return ptr; // Se for igual, retornamos este nodo
        else
            ptr = ptr->prox; // Senão, vamos para o próximo nodo da lista
    }
    return NULL; // Retorna nulo se não encontrar na lista a palavra
}

/** Função que cria um nodo com a descrição definida na linha 9-12 de nodos para a lista sem repetição.
 *  Retorno: referência para o nodo criado no escopo da função.
 */
NodoSEMREP* criaNodoSEMREP(char *palavra) {
    NodoSEMREP *nodo;

    nodo = (NodoSEMREP *) malloc(sizeof(NodoSEMREP));

    if (nodo == NULL) {
        printf("Erro de alocação\n");
        return NULL;
    }

    nodo->palavra = palavra;
    nodo->prox = NULL;

    return nodo;
}

/** Função que adiciona um nodo na lista sem repetição.
 *  Retorno: referência para o nodo adicionado ou já existente na lista sem repetição.
 */
NodoSEMREP* addNodoSEMREP(char *palavra) {
    NodoSEMREP *ptr;

    ptr = existePlavraNaLista(palavra); // O ponteiro aponta para o que esta função retornar

    if (inicioSEMREP != NULL) { // Se a lista não estiver vazia
        if(ptr == NULL) { // Se a palavra não existir na lista
            ptr = inicioSEMREP; // O ponteiro aponta para o inicio da lista
            while(ptr->prox != NULL) // Iteramos a lista até encontrar uma referência para o nodo seguinte nula
                ptr = ptr->prox;
            ptr->prox = criaNodoSEMREP(palavra); // E então adicionamos como último nodo da lista o que contenha a palavra retornado por esta função
            return ptr->prox;
        }
        else
            return ptr; // Se a palavra estiver na lista, então retornamos o ponteiro
    }
    else
        inicioSEMREP = criaNodoSEMREP(palavra); // Se a lista estiver vazia, simplesmente adicionamos o nodo criado por esta função no inicio da lista

    return inicioSEMREP; // Retornamos o nodo criado no inicio da lista
}

void printListaSEMREP() {
    NodoSEMREP *ptrSEMREP;

    if (inicioSEMREP == NULL) {
        printf("LISTA SEM REPETIÇÃO VAZIA\n\n");
        return;
    }

    printf("LISTA SEM REPETIÇÃO:\n");

    ptrSEMREP = inicioSEMREP;

    while (ptrSEMREP != NULL) {
        printf("\"%s\", ", ptrSEMREP->palavra);
        ptrSEMREP = ptrSEMREP->prox;
    }

    printf("\n\n");
}

void esvaziaListaSEMREP() {
    NodoSEMREP *aux, *temp;
    aux = inicioSEMREP;
    while (aux != NULL) {
        temp = aux->prox;
        free(aux->palavra); // Libera a memória alocada para a palavra
        free(aux); // Libera a memória alocada para o nodo
        aux = temp;
    }
    inicioSEMREP = NULL;
}

int sizeListaSEMREP() {
    int size = 0;
    NodoSEMREP *aux;
    aux = inicioSEMREP;
    while(aux != NULL) {
        size++;
        aux = aux->prox;
    }
    return size-1; // Por conta da última linha do arquivo ser vazia, é criado um nodo a mais.
}

NodoSEMREP* getInicioSEMREP() {
    return inicioSEMREP;
}
