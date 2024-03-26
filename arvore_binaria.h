#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_de_adjascencia.h" // Inclua o arquivo que define as estruturas do grafo

typedef struct info {
    TipoGrafo grafo;
} Info;

typedef Info TipoChave;
typedef struct Registro {
  TipoChave Chave;
  /*outros componentes */
} Registro;
typedef struct No *Apontador;

typedef struct No {
  Registro Reg;
  Apontador Esq, Dir;
} No;
typedef Apontador TipoDicionario;

void Inicializa_binaria(Apontador *Dicionario);

int Vazio_binaria(Apontador *Dicionario);

void PosFixado_binaria(Apontador *p);

void Insere_binaria(Registro x, Apontador *p);

void Antecessor_binaria(Apontador q, Apontador *r);

void Retira_binaria(Registro x, Apontador *p);

/*
void Central(Apontador *p);

void PreFixado(Apontador *p);

Registro *Pesquisa(char *x, Apontador *p);
Registro *Menor(Apontador *p);

Registro *Maior(Apontador *p);

int AlturaMax(Apontador *p);

*/


