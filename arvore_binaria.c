#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"

void Inicializa(Apontador *Dicionario) { *Dicionario = NULL; }

int Vazio(Apontador *Dicionario) { return (Dicionario == NULL); }

void PosFixado(Apontador *p) {
  if (*p == NULL)
    return;
  PosFixado(&(*p)->Esq);
  PosFixado(&(*p)->Dir);
  printf("%s\n", (*p)->Reg.Chave.cep);
}

void Central(Apontador *p) {
  if (*p == NULL)
    return;
  Central(&(*p)->Esq);
  printf("%s\n", (*p)->Reg.Chave.cep);
  Central(&(*p)->Dir);
}

void PreFixado(Apontador *p) {
  if (*p == NULL)
    return;
  printf("%s\n", (*p)->Reg.Chave.cep);
  PreFixado(&(*p)->Esq);
  PreFixado(&(*p)->Dir);
}

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

void Insere(Registro x, Apontador *p) {
  if (*p == NULL) {
    *p = (Apontador)malloc(sizeof(No));
    (*p)->Reg = x;
    (*p)->Esq = NULL;
    (*p)->Dir = NULL;
    return;
  }
  if (strcmp(x.Chave.cep, (*p)->Reg.Chave.cep) < 0) {
    Insere(x, &(*p)->Esq);
    return;
  }
  if (strcmp(x.Chave.cep, (*p)->Reg.Chave.cep) > 0)
    Insere(x, &(*p)->Dir);
}

void Antecessor(Apontador q, Apontador *r) {
  if ((*r)->Dir != NULL) {
    Antecessor(q, &(*r)->Dir);
    return;
  }
  q->Reg = (*r)->Reg;
  q = *r;
  *r = (*r)->Esq;
  free(q);
}

void Retira(Registro x, Apontador *p) {
  Apontador Aux;
  if (*p == NULL) {
    printf("Erro: Registro nao esta na arvore \n");
    return;
  }
  if (strcmp(x.Chave.cep, (*p)->Reg.Chave.cep) < 0) {
    Retira(x, &(*p)->Esq);
    return;
  }
  if (strcmp(x.Chave.cep, (*p)->Reg.Chave.cep) > 0) {
    Retira(x, &(*p)->Dir);
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