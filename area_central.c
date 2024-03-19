#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista_de_adjascencia.c"

// Definições de estruturas e funções...

int main()
{
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com o tempo atual

    TipoGrafo Grafo;
    TipoValorVertice NVertices;
    int NArestas;
    FILE *arquivo;
    char nome_arquivo[] = "Grafo da Area Central.txt";

    printf("Digite o numero de vertices do grafo: ");
    scanf("%d", &NVertices);
    getchar(); // Limpa o buffer do teclado

    printf("Digite o numero de arestas do grafo: ");
    scanf("%d", &NArestas);
    getchar(); // Limpa o buffer do teclado

    // Inicializa o grafo
    Grafo.NumVertices = NVertices;
    Grafo.NumArestas = 0;
    FGVazio(&Grafo);

    // Insere arestas aleatórias com pesos aleatórios
    for (int i = 0; i < NArestas/2; i++) {
        TipoValorVertice V1 = i; // Vértice de origem aleatório
        TipoValorVertice V2 = i+1; // Vértice de destino aleatório
        TipoPeso Peso = 1; // Peso aleatório entre 0 e 99

        InsereAresta(&V1, &V2, &Peso, &Grafo);
        Peso *=-1;
        InsereAresta(&V2, &V1, &Peso, &Grafo);
    }

    // Abre o arquivo para escrita
    arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    // Escreve o grafo no arquivo
    fprintf(arquivo, "%d\n", Grafo.NumVertices); // Numero de vertices
    fprintf(arquivo, "%d\n", Grafo.NumArestas); // Número de arestas

    for (int i = 0; i < Grafo.NumVertices; i++) {
        TipoApontador Aux = PrimeiroListaAdj(&i, &Grafo);
        while (Aux != NULL) {
            fprintf(arquivo, "%d %d %d\n", i, Aux->Item.Vertice, Aux->Item.Peso);
            Aux = Aux->Prox;
        }
    }

    fclose(arquivo);
    printf("Grafo salvo com sucesso no arquivo %s\n", nome_arquivo);

    return 0;
}
