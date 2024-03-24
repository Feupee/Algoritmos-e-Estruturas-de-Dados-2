#define MAXVERTICES 100
#define INF 999999

typedef struct Aresta {
    int sala; //aresta em específico aponta para aquela sala
    int peso; //peso
}aresta;

typedef struct Vertice {
    int nomeSala; // índice do vértice
    aresta *ListaADJ; // Lista de outras salas que o vértice aponta
    int nADJ; //quantidade de elementos da lista
}vertice;

typedef struct grafo{
    vertice sala[MAXVERTICES];
    int nVertices;
}grafo;

typedef struct HeapNo {
    int vertice;
    int custo;
} HeapNo;

typedef struct MinHeap {
    int tamanho;
    int capacidade;
    HeapNo *arr;
} MinHeap;

typedef struct Fila{
    int elementos[MAXVERTICES];
    int inicio;
    int fim;
} Fila;


void criaVertice(grafo *g, char *Professor);
int existeAresta(grafo *g, char *Professor1, char *Professor2);
void criaAresta(grafo *g, char *Professor1, char *Professor2, int colabs);
void imprimegrafo(grafo *g);
grafo *criagrafo();
int existeVertice(grafo *g, char *Professor);
void caminhoKdistancia(grafo *g, char *u, int d);
int buscaVertice(grafo *g, char *Professor);
void imprimeOrigem(grafo *g, int Professor);
//-----------------------------------
void exibirCoautores(grafo *g, char professor[], int K);
//-----------------------------------
//letra d)
void buscaDFS(grafo *g, int u, int *visitados, int *componente);
void buscaDFStransposto(grafo *g, int u, int *visitados, int *componente);
void fortementeConectados(grafo *g, char *Professor);
//-----------------------------------

//-----------------------------------------------------
HeapNo criarNo(int vertice, int custo);
MinHeap criarMinHeap(int capacidade);
void trocarNos(HeapNo *a, HeapNo *b);
void minHeapify(MinHeap *minHeap, int indice);
int isEmpty(MinHeap *minHeap);
HeapNo extrairMinimo(MinHeap *minHeap);
void diminuirChave(MinHeap *minHeap, int vertice, int custo);
void encontrarCaminhoMinimo(grafo *g, char P1[], char P2[]);
//------------------------------------
void inicializarFila(Fila *fila);
void enfileirar(Fila *fila, int valor);
int desenfileirar(Fila *fila);
int filaVazia(Fila *fila);
void BFS(grafo *g, int inicio, int distanciaLimite);
void mostraCoautores(grafo *g, char *professor, int K);
