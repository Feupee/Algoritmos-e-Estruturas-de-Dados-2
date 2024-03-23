#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_de_adjascencia_sem_peso.h"


// Definições de estruturas e funções...

void percurso(TipoValorVertice verticeA, TipoArea*Grafo){
    ImprimeLista(Grafo->Adj[verticeA]); // Imprime seus adjascentes
    int escolha, i=0;
    printf("Escolha o vertice por indice: 1,2,3...\n");
    scanf("%d ", &escolha);

    TipoApontador Aux = PrimeiroListaAdj(&verticeA, Grafo);

    if(Aux->Item.Vertice == -1){
        // Se o vertice aponta pra -1, ele é o vertice de SAIDA. entao GANHOU
        /*
         Vertice 0:  3 (12523024)  2 (12523024)
            Vertice 1:  3 (12523024)  4 (12523024)
            Vertice 2: 
            Vertice 3:  5 (12523024)
            Vertice 4:  -1
            Vertice -1: Indica que ganha apenas n faz nada. 
        */
    }

    if(Aux == NULL){
        int escolha_gameover;      //GAMEOVER  
        printf("Gameover: 1-ENCERRAR, 2-JOGAR NOVAMENTE\n");
        do{
        scanf("%d",&escolha_gameover);
        if(escolha_gameover == 1){
            //system("cls");
            printf("GAMEOVER");
           // exit(0);
        }
        else{
            percurso(0,Grafo); //Chama o percurso NOVAMENTE para vertice INICIAL
        }
        }while(escolha_gameover<0 && escolha_gameover>2);
    }

    while (Aux->Prox != NULL && i != escolha) {
        printf("%3d", Aux->Item.Vertice);
        Aux = Aux->Prox;
        i++;
    }
    // Chama o percurso a partir daquele vertice.
    percurso(Aux->Item.Vertice, Grafo);

}



int main() {
    TipoArea Grafo;
    strcpy(Grafo.Dificuldade, "Facil"); //Excluir, isso é somente um exemplo
    TipoValorVertice V1, V2;
    int NVertices, NArestas; // Definindo NVertices e NArestas aqui
    // Leitura dos 5 grafos a partir dos arquivos
    char file_name[15] = "Area 1 Facil.txt"; // Ajuste o tamanho conforme necessário .Função para armazenar o nome do arquivo .txt no buffer
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", file_name);
        system("pause");
        return 1;
    }

        printf("Carregando Area 1...\n");
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
        system("pause");
    return 0;
}

/*int main() {
    TipoArea Grafo;
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
}*/

