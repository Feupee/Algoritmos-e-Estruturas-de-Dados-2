#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista_de_adjascencia.c"
#include <windows.h>

// Definições de estruturas e funções...

int pontuacao, vitorias, derrotas; //    Ajustar para JOGADOR

void percurso(TipoValorVertice verticeA, TipoGrafo *Grafo)
{
    if (verticeA == Grafo->NumVertices - 1)
    {
        /*
            VENCE (chegou no N-ésimo Vértice)
            Incrementar VITORIAS em 3
        */
        vitorias += 3;
        return;
    }

    printf("=== SALA ATUAL: [%d]       PONTUACAO ATUAL: [%d] ===\n\n", verticeA, pontuacao);
    int escolha;
    TipoApontador Aux = PrimeiroListaAdj(&verticeA, Grafo);

    // --------- Verificando GAMEOVER, (nao tem pontos para andar)---------
    int ver = 1;
    while (Aux != NULL)
    {
        if (pontuacao + Aux->Item.Peso >= 0)
        {
            ver = 0;
        }
        Aux = Aux->Prox;
    }
    if (ver == 1)
    {
        printf("\n<< GAMEOVER >>   << VOCE NAO TEM PONTOS PARA CAMINHAR!! >>\n");
        derrotas++;
        return;
    }

    while (1)
    { // Para ver se ELE PODE IR PARA TAL VERTICE

        Aux = PrimeiroListaAdj(&verticeA, Grafo);
        while (1)
        {
            Aux = PrimeiroListaAdj(&verticeA, Grafo);
            printf("\nEscolha a SALA...\n");
            ImprimeLista(Grafo->Adj[verticeA]); // Imprime seus adjascentes

            scanf("%d", &escolha);
            
            while (Aux->Prox != NULL)
            {
                if (Aux->Item.Vertice == escolha)
                    break;
                Aux = Aux->Prox;
            }
            if (Aux->Item.Vertice == escolha)
            {
                // Achou o vertice
                break;
            }
            else
            {
                printf(" -- Voce nao pode VISITAR esta SALA! -- \n\n");
            }
        }

        // Chama o percurso a partir daquele vertice.
        if (pontuacao + Aux->Item.Peso >= 0)
        {
            break;
        }
        else
        {
            printf("PONTUACAO INSUFICIENTE!!\n");
        }
    }

    pontuacao += Aux->Item.Peso; // Somando a pontuacao
    percurso(Aux->Item.Vertice, Grafo);
}

int main()
{
    TipoGrafo Grafo;
    FILE *arquivo;
    char nome_arquivo[] = "Grafo da Area Central.txt";
    int NVertices, NArestas;

    // Abre o arquivo para leitura
    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL)
    {
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
    for (int i = 0; i < NArestas; i++)
    {
        int V1, V2, Peso;
        fscanf(arquivo, "%d %d %d", &V1, &V2, &Peso);
        InsereAresta(&V1, &V2, &Peso, &Grafo);
    }

    fclose(arquivo);


    // ----- Inicializar a função de PERCURSO no LABIRINTO -----
    vitorias = 0;
    derrotas = 0;
    while (1)
    {
        printf("\nDeseja jogar? se Nao pressione 0!\n");
        int jogar = 1;
        scanf("%d", &jogar);
        if (jogar == 0)
            break;
        pontuacao = 0; // Jogador começa com 0 de pontos
        printf("----- INICIO DO LABIRINTO -----\n\n");
        percurso(0, &Grafo);
        printf("\nBom JOGO! JOGADOR1!!\nPontuacao = [%d]\nVitorias = [%d]\nDerrotas = [%d]\n", pontuacao, vitorias,derrotas);
    }

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
