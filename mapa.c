#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <arvore_binaria.c>


void pause() {
  printf("Aperte enter para continuar\n");
  getchar();
  // system("clear");
}

int main() {

  Registro *busca, aux, *maiorReg, *menorReg;
  TipoGrafo grafos;
  int i = 0;

  TipoDicionario Dicionario;
  Inicializa(&Dicionario);
  // A partir daqui ler todos as AREAS e AREA CENTRAL para depois fazer o percurso POS-FIXADO

  FILE *arquivo = fopen("area", "r");

  while (fscanf(arquivo, "%[^;];%2[^;];%[^;];%[^\n]\n", grafos) != EOF) { // LER DO ARQUIVO O GRAFO
    aux.Chave.grafo = grafos;
    Insere_binaria(aux, &Dicionario);
  }

  fclose(arquivo);
    // Agora começar o Jogo

  printf("Inicio do GAME:\n");
  PosFixado_binaria(&Dicionario);
  pause();

}
