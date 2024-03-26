#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"
#include "lista_de_adjascencia.c"

void Inicializa_binaria(Apontador *Dicionario) { *Dicionario = NULL; }

int Vazio_binaria(Apontador *Dicionario) { return (Dicionario == NULL); }

void PosFixado_binaria(Apontador *p) {
  if (*p == NULL)
    return;
  PosFixado_binaria(&(*p)->Esq);
  PosFixado_binaria(&(*p)->Dir);

  //OPERACAO, (VISITA):
    TipoGrafo *aux;
    *aux = (*p)->Reg.Chave.grafo;
    percursoCentral(0,aux);

}

void Insere_binaria(Registro x, Apontador *p) {
  if (*p == NULL) {
    *p = (Apontador)malloc(sizeof(No));
    (*p)->Reg = x;
    (*p)->Esq = NULL;
    (*p)->Dir = NULL;
    return;
  }

  if (strcmp(x.Chave.grafo.NumVertices, (*p)->Reg.Chave.grafo.NumVertices) < 0) {
    Insere_binaria(x, &(*p)->Esq);
    return;
  }
  if (strcmp(x.Chave.grafo.NumVertices, (*p)->Reg.Chave.grafo.NumVertices) > 0)
    Insere_binaria(x, &(*p)->Dir);
}

void Antecessor_binaria(Apontador q, Apontador *r) {
  if ((*r)->Dir != NULL) {
    Antecessor_binaria(q, &(*r)->Dir);
    return;
  }
  q->Reg = (*r)->Reg;
  q = *r;
  *r = (*r)->Esq;
  free(q);
}

void Retira_binaria(Registro x, Apontador *p) {
  Apontador Aux;
  if (*p == NULL) {
    printf("Erro: Registro nao esta na arvore \n");
    return;
  }
  if (strcmp(x.Chave.grafo.NumVertices, (*p)->Reg.Chave.grafo.NumVertices) < 0) {
    Retira_binaria(x, &(*p)->Esq);
    return;
  }
  if (strcmp(x.Chave.grafo.NumVertices, (*p)->Reg.Chave.grafo.NumVertices) > 0) {
    Retira_binaria(x, &(*p)->Dir);
    return;
  }
  if ((*p)->Esq != NULL) {
    Antecessor(*p, &(*p)->Esq);
    return;
  }
  Aux = *p;
  *p = (*p)->Dir;
  free(Aux);
}

/*

Registro *Pesquisa(char *x, Apontador *p) {
  if (*p == NULL)
    return NULL;

  if (strcmp(x, (*p)->Reg.Chave.cep) < 0)
    return Pesquisa(x, &(*p)->Esq);

  else if (strcmp(x, (*p)->Reg.Chave.cep) > 0)
    return Pesquisa(x, &(*p)->Dir);

  else
    return &(*p)->Reg;
}

Registro *Menor(Apontador *p) {
  if ((*p)->Esq == NULL) {
    return &((*p)->Reg);
  }
  Menor(&((*p)->Esq));
}

Registro *Maior(Apontador *p) {
  if ((*p)->Dir == NULL) {
    return &((*p)->Reg);
  }
  Maior(&((*p)->Dir));
}

int AlturaMax(Apontador *p) {
  if (*p == NULL)
    return 0;

  int alturaD = AlturaMax(&((*p)->Dir));
  int alturaE = AlturaMax(&((*p)->Esq));

  if (alturaD > alturaE)
    return 1 + alturaD;

  return 1 + alturaE;
}
*/