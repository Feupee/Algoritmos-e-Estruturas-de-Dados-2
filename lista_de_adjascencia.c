#include <stdio.h>
#include <stdlib.h>
#include "lista_de_adjascencia.h"

TipoApontador Aux;
long i;
short FimListaAdj;
int  NArestas;
TipoPeso Peso;
TipoValorVertice NVertices;

/*--Entram aqui os operadores do Programa 2.4--*/
void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

short Vazia(TipoLista Lista) {
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem *x, TipoLista *Lista) {
    /*-- Insere depois do ultimo item da lista --*/
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = *x;
    Lista->Ultimo->Prox = NULL;
}

/*-- Fim operadores do Programa 2.4 --*/
void FGVazio(TipoGrafo *Grafo) {
    long i;
    for (i = 0; i < Grafo->NumVertices; i++)
        FLVazia(&Grafo->Adj[i]);
}

void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2,
                  TipoPeso *Peso, TipoGrafo *Grafo) {
    TipoItem x;
    x.Vertice = *V2;
    x.Peso = *Peso;
    Insere(&x, &Grafo->Adj[*V1]);
}

short ExisteAresta(TipoValorVertice Vertice1,
                   TipoValorVertice Vertice2, TipoGrafo *Grafo) {
    TipoApontador Aux;
    short EncontrouAresta = FALSE;
    Aux = Grafo->Adj[Vertice1].Primeiro->Prox;
    while (Aux != NULL && EncontrouAresta == FALSE) {
        if (Vertice2 == Aux->Item.Vertice) EncontrouAresta = TRUE;
        Aux = Aux->Prox;
    }
    return EncontrouAresta;
}

/* Operadores para obter a lista de adjacentes */
short ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo) {
    return (Grafo->Adj[*Vertice].Primeiro == Grafo->Adj[*Vertice].Ultimo);
}

TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice,
                               TipoGrafo *Grafo) {
    return (Grafo->Adj[*Vertice].Primeiro->Prox);
}

void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo,
             TipoValorVertice *Adj, TipoPeso *Peso,
             TipoApontador *Prox, short *FimListaAdj) {
    /* Retorna Adj e Peso do Item apontado por Prox */
    *Adj = (*Prox)->Item.Vertice;
    *Peso = (*Prox)->Item.Peso;
    *Prox = (*Prox)->Prox;
    if (*Prox == NULL)
        *FimListaAdj = TRUE;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item) {
    /*--Obs.: item a ser retirado e o seguinte ao apontado por p--*/
    TipoApontador q;
    if (Vazia(*Lista) || p == NULL || p->Prox == NULL) {
        printf("Erro: Lista vazia ou posicao nao existe\n");
        return;
    }
    q = p->Prox;
    *Item = q->Item;
    p->Prox = q->Prox;
    if (p->Prox == NULL)
        Lista->Ultimo = p;
    free(q);
}

void RetiraAresta(TipoValorVertice *V1, TipoValorVertice *V2,
                  TipoPeso *Peso, TipoGrafo *Grafo) {
    TipoApontador AuxAnterior, Aux;
    short EncontrouAresta = FALSE;
    TipoItem x;
    AuxAnterior = Grafo->Adj[*V1].Primeiro;
    Aux = Grafo->Adj[*V1].Primeiro->Prox;
    while (Aux != NULL && EncontrouAresta == FALSE) {
        if (*V2 == Aux->Item.Vertice) {
            Retira(AuxAnterior, &Grafo->Adj[*V1], &x);
            Grafo->NumArestas--;
            EncontrouAresta = TRUE;
        }
        AuxAnterior = Aux;
        Aux = Aux->Prox;
    }
}

void LiberaGrafo(TipoGrafo *Grafo) {
    TipoApontador AuxAnterior, Aux;
    for (i = 0; i < Grafo->NumVertices; i++) {
        Aux = Grafo->Adj[i].Primeiro->Prox;
        free(Grafo->Adj[i].Primeiro);   /*Libera celula cabeca*/
        Grafo->Adj[i].Primeiro=NULL;
        while (Aux != NULL) {
            AuxAnterior = Aux;
            Aux = Aux->Prox;
            free(AuxAnterior);
        }
    }
    Grafo->NumVertices = 0;
}

void ImprimeGrafo(TipoGrafo *Grafo) {
    int i;
    TipoApontador Aux;
    for (i = 0; i < Grafo->NumVertices; i++) {
        printf("Vertice%2d:", i);
        if (!Vazia(Grafo->Adj[i])) {
            Aux = Grafo->Adj[i].Primeiro->Prox;
            while (Aux != NULL) {
                printf("%3d (%d)", Aux->Item.Vertice, Aux->Item.Peso);
                Aux = Aux->Prox;
            }
        }
        putchar('\n');
    }
}

void ImprimeLista(TipoLista Lista) {
    TipoApontador Aux;
    Aux = Lista.Primeiro->Prox;
    while (Aux != NULL) {
        printf("SALA: [%d] ---- VALOR: (%d)\n", Aux->Item.Vertice, Aux->Item.Peso);
        Aux = Aux->Prox;
    }
}

void GrafoTransposto(TipoGrafo *Grafo, TipoGrafo *GrafoT) {
    TipoValorVertice v, Adj;
    TipoPeso Peso;
    TipoApontador Aux;
    GrafoT->NumVertices = Grafo->NumVertices;
    GrafoT->NumArestas = Grafo->NumArestas;
    FGVazio(GrafoT);
    for (v = 0; v <= Grafo->NumVertices - 1; v++) {
        if (!ListaAdjVazia(&v, Grafo)) {
            Aux = PrimeiroListaAdj(&v, Grafo);
            FimListaAdj = FALSE;
            while (!FimListaAdj) {
                ProxAdj(&v, Grafo, &Adj, &Peso, &Aux, &FimListaAdj);
                InsereAresta(&Adj, &v, &Peso, GrafoT);
            }
        }
    }
}