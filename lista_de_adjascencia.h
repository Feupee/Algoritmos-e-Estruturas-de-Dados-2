#ifndef TAD_H
#define TAD_H

#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   4500
#define FALSE           0
#define TRUE            1

typedef int TipoValorVertice;
typedef int TipoPeso;

typedef struct TipoItem {
    TipoValorVertice Vertice;
    TipoPeso Peso;
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct TipoLista {
    TipoApontador Primeiro, Ultimo;
} TipoLista;

typedef struct TipoGrafo {
    TipoLista Adj[MAXNUMVERTICES];
    int NumVertices;
    int NumArestas;
} TipoGrafo;

void FLVazia(TipoLista *Lista);
short Vazia(TipoLista Lista);
void Insere(TipoItem *x, TipoLista *Lista);
void FGVazio(TipoGrafo *Grafo);
void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo);
short ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2, TipoGrafo *Grafo);
short ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo);
TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo);
void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo, TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox, short *FimListaAdj);
void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item);
void RetiraAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo);
void LiberaGrafo(TipoGrafo *Grafo);
void ImprimeGrafo(TipoGrafo *Grafo);
void ImprimeLista(TipoLista Lista);
void GrafoTransposto(TipoGrafo *Grafo, TipoGrafo *GrafoT);

#endif
