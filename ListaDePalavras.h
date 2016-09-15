#ifndef LISTADEPALAVRAS_H_INCLUDED
#define LISTADEPALAVRAS_H_INCLUDED
/** DEFINE A ESTRUTURA DOS NODOS
 * NodoSEMREP: nodo que possui a palavra.
 */
typedef struct Nodo0 {
    char *palavra;
    struct Nodo0 *prox;
} NodoSEMREP;

void inicializaListaDePalavras();
NodoSEMREP* existePlavraNaLista(char *palavra);
NodoSEMREP* criaNodoSEMREP(char *palavra);
NodoSEMREP* addNodoSEMREP(char *palavra);
void printListaSEMREP();
void esvaziaListaSEMREP();
int sizeListaSEMREP();
NodoSEMREP* getInicioSEMREP();
#endif // LISTADEPALAVRAS_H_INCLUDED
