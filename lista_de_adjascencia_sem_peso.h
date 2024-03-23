#include <stdio.h>
#include <stdlib.h>

// Definições de constantes
#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   4500
#define FALSE           0
#define TRUE            1

// Definição do tipo de dado para representar o valor de um vértice
typedef int TipoValorVertice;

// Definição da estrutura de um item na lista de adjacências
typedef struct TipoItem {
    TipoValorVertice Vertice;
} TipoItem;


// Definição de um ponteiro para a célula na lista de adjacências

// Definição da estrutura de uma célula na lista de adjacências

// PARTE ------------------------------------------
/*
typedef struct TipoCelula *TipoApontador;
struct TipoCelula {
    TipoItem Item;
    TipoApontador Prox;
};
*/

typedef struct TipoCelula {
    TipoItem Item;
    struct TipoCelula *Prox;
} TipoCelula;

typedef TipoCelula *TipoApontador;




// Definição da estrutura de uma lista de adjacências
typedef struct TipoLista {
    TipoApontador Primeiro, Ultimo;
} TipoLista;

// Definição da estrutura de um grafo
typedef struct TipoArea {
    int NumVertices;
    int NumArestas;
    TipoLista Adj[MAXNUMVERTICES];
    char Dificuldade[15];
} TipoArea;

// Variáveis globais
TipoApontador Aux; // Apontador auxiliar para iteração na lista de adjacências
long i; // Variável para iteração
short FimListaAdj; // Indica se a lista de adjacências chegou ao fim
int NArestas; // Número de arestas
TipoValorVertice NVertices; // Número de vértices

// Protótipos das funções
void FLVazia(TipoLista *Lista);
short Vazia(TipoLista Lista);
void Insere(TipoItem *x, TipoLista *Lista);
void FGVazio(TipoArea *Grafo);
void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoArea *Grafo);
short ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2, TipoArea *Grafo);
short ListaAdjVazia(TipoValorVertice *Vertice, TipoArea *Grafo);
TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoArea *Grafo);
void ProxAdj(TipoValorVertice *Vertice, TipoArea *Grafo, TipoValorVertice *Adj, TipoApontador *Prox, short *FimListaAdj);
void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item);
void RetiraAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoArea *Grafo);
void LiberaGrafo(TipoArea *Grafo);
void ImprimeGrafo(TipoArea *Grafo);
void ImprimeLista(TipoLista Lista);
void GrafoTransposto(TipoArea *Grafo, TipoArea *GrafoT);
void encerraPrograma();