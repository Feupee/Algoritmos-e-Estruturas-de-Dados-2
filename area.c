#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_de_adjascencia_sem_peso.h"

// Definições de estruturas e funções...

int main() {
    TipoGrafo Grafo;
    strcpy(Grafo.Dificuldade, "Facil"); //Excluir, isso é somente um exemplo
    TipoValorVertice V1, V2;
    int NVertices, NArestas; // Definindo NVertices e NArestas aqui
    // Leitura dos 5 grafos a partir dos arquivos
    for (int i = 1; i <= 5; i++) {
        char file_name[15]; // Ajuste o tamanho conforme necessário
        sprintf(file_name, "Area %d %s.txt", i, Grafo.Dificuldade); //Função para armazenar o nome do arquivo .txt no buffer
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
            InsereAresta(&V1, &V2, &Grafo);
        }

        // Impressão do grafo
        ImprimeGrafo(&Grafo);

        // Processamento adicional, se necessário

        fclose(file);
    }

        system("pause");
    return 0;
}

