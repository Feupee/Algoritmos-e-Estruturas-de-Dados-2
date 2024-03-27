#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <arvore_binaria.c>

typedef struct {
    char name[40];
    int vitorias;
    int derrotas;
} Jogador;


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
  TipoGrafo Grafo;
  TipoValorVertice V1, V2;
    int NVertices, NArestas; // Definindo NVertices e NArestas aqui
    // Leitura dos 5 grafos a partir dos arquivos
    for (int i = 1; i <= 5; i++) {
        char file_name[15]; // Ajuste o tamanho conforme necessário
        sprintf(file_name, "Areas/Facil/Area %d %s.txt", i, Grafo.Dificuldade); //Função para armazenar o nome do arquivo .txt no buffer
        FILE *file = fopen(file_name, "r");
        if (file == NULL) {
            printf("Erro ao abrir o arquivo %s\n", file_name);
            system("pause");
            return 1;
        }

        printf("Carregando Area %d...\n", i);
        // Inicialização da Area
        // Leitura do número de vértices e arestas
        fscanf(file, "%d %d", &NVertices, &NArestas); // Correção: definindo NVertices e NArestas
        Grafo.NumVertices = NVertices;
        Grafo.NumArestas = 0;
        FGVazio(&Grafo);

        // Leitura das arestas
        for (int j = 0; j < NArestas; j++) {
            fscanf(file, "%d %d", &V1, &V2);
            Grafo.NumArestas++;
            InsereAresta(&V1, &V2, 0, &Grafo);
        }

        // Impressão do grafo
        ImprimeGrafo(&Grafo);

        fclose(file);
    }

  FILE *arquivo = fopen("area", "r");
  /*
    --> 1010
    --> 0101
    -->
  */

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
