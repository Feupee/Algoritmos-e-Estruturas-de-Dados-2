#include <stdio.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int vitorias;
    int derrotas;
    int pontos;
} Jogador;

int jogadorExiste(char *nomeBusca) {
    FILE *pont_arq;
    char nome[MAX_NOME];
    
    // Abrindo o arquivo em modo leitura
    pont_arq = fopen("ranking.txt", "r");
    
    // Verificando se o arquivo foi aberto corretamente
    if (pont_arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    // Lendo linha por linha e comparando o nome buscado
    while (fgets(nome, MAX_NOME, pont_arq) != NULL) {
        // Removendo o caractere de nova linha
        nome[strlen(nome) - 1] = '\0';

        // Comparando o nome buscado com o nome lido do arquivo
        if (strcmp(nome, nomeBusca) == 0) {
            // Fechando o arquivo e retornando verdadeiro se o nome foi encontrado
            fclose(pont_arq);
            return 1;
        }
    }

    // Fechando o arquivo e retornando falso se o nome não foi encontrado
    fclose(pont_arq);
    return 0;
}

int main() {
    char nomeBusca[MAX_NOME];

    printf("Digite o nome do jogador que deseja verificar: ");
    fgets(nomeBusca, MAX_NOME, stdin);
    nomeBusca[strlen(nomeBusca) - 1] = '\0'; // Removendo o caractere de nova linha

    if (jogadorExiste(nomeBusca)) {
        printf("O jogador %s existe no ranking.\n", nomeBusca);
    } else {
        printf("O jogador %s nao existe no ranking.\n", nomeBusca);
    }

    return 0;
}