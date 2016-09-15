#ifndef TEXTOCOMOLISTADEPALAVRAS_H_INCLUDED
#define TEXTOCOMOLISTADEPALAVRAS_H_INCLUDED
/** DEFINE A ESTRUTURA DOS NODOS
 * NodoCOMREP: nodo que possui referência para o nodo que possui a palavra.
 */
typedef struct Nodo1 {
    NodoSEMREP *nodo;
    struct Nodo1 *prox;
} NodoCOMREP;

void inicializaTextoComoListaDePalavras();
NodoCOMREP* criaNodoCOMREP(char *palavra);
void addNodoCOMREP(char *palavra);
void printListaCOMREP();
void esvaziaListaCOMREP();
int sizeListaCOMREP();
NodoCOMREP* getInicioCOMREP();
#endif // TEXTOCOMOLISTADEPALAVRAS_H_INCLUDED
