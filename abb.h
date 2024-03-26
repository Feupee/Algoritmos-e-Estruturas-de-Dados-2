#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info {
  char cep[10];
  char estado[3];
  char cidade[50];
  char rua[100];
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

void Inicializa(Apontador *Dicionario);

int Vazio(Apontador *Dicionario);

void PosFixado(Apontador *p);

void Central(Apontador *p);

void PreFixado(Apontador *p);

Registro *Pesquisa(char *x, Apontador *p);

void Insere(Registro x, Apontador *p);

void Antecessor(Apontador q, Apontador *r);

void Retira(Registro x, Apontador *p);

Registro *Menor(Apontador *p);

Registro *Maior(Apontador *p);

int AlturaMax(Apontador *p);
