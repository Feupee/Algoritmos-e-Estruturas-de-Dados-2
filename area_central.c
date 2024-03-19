#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista_de_adjascencia.c"

// Definições de estruturas e funções...

void imprimirLabirinto(TipoGrafo *Grafo) {
    printf("Labirinto:\n");

    // Imprime as paredes superiores do labirinto
    for (int i = 0; i < Grafo->NumVertices; i++) {
        printf("+--");
    }
    printf("+\n");

    // Imprime o corpo do labirinto
    for (int i = 0; i < Grafo->NumVertices; i++) {
        TipoApontador Aux = PrimeiroListaAdj(&i, Grafo);
        while (Aux != NULL) {
            printf("|  ");
            Aux = Aux->Prox;
        }
        printf("|\n");

        // Imprime as paredes laterais direitas do labirinto
        if (i < Grafo->NumVertices - 1) {
            printf("+");
            Aux = PrimeiroListaAdj(&i, Grafo);
            while (Aux != NULL) {
                printf("%d",Aux->Item.Vertice);
                Aux = Aux->Prox;
            }
            printf("+\n");
        }
    }

    // Imprime a parede inferior do labirinto
    for (int i = 0; i < Grafo->NumVertices; i++) {
        printf("+--");
    }
    printf("+\n");
}

int main() {
    TipoGrafo Grafo;
    FILE *arquivo;
    char nome_arquivo[] = "Grafo da Area Central.txt";
    int NVertices, NArestas;

    // Abre o arquivo para leitura
    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    // Lê o número de vértices e arestas do arquivo
    fscanf(arquivo, "%d", &NVertices);
    fscanf(arquivo, "%d", &NArestas);

    // Inicializa o grafo
    Grafo.NumVertices = NVertices;
    Grafo.NumArestas = NArestas;
    FGVazio(&Grafo);

    // Lê as arestas do arquivo e insere no grafo
    for (int i = 0; i < NArestas; i++) {
        int V1, V2, Peso;
        fscanf(arquivo, "%d %d %d", &V1, &V2, &Peso);
        InsereAresta(&V1, &V2, &Peso, &Grafo);
    }

    fclose(arquivo);

    // Imprime o labirinto correspondente ao grafo lido
    imprimirLabirinto(&Grafo);

    return 0;
}



/*
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
*/
