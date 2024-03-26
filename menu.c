#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define MAX_NOME 100

int a,b,L,L2; // Declaração das váriaveis das setas
int co,L3,L4; // Novas declarações do menu

void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

typedef struct {
    char nome[MAX_NOME];
    int vitorias;
    int derrotas;
    int pontos;
} Jogador;

typedef struct {
    char dificuldade[20];
} Jogo_config;

void adicionarVitoria(const char *nomeJogador) {
    FILE *pont_arq;
    Jogador jogador;
    FILE *temp_arq;
    char linha[MAX_NOME + 20]; // Tamanho máximo da linha no arquivo
    char temp_nome[] = "temp_ranking.txt"; // Nome do arquivo temporário

    // Abre o arquivo original no modo leitura
    pont_arq = fopen("ranking.txt", "r");
    if (pont_arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Abre um arquivo temporário no modo escrita
    temp_arq = fopen(temp_nome, "w");
    if (temp_arq == NULL) {
        printf("Erro ao abrir o arquivo temporário.\n");
        fclose(pont_arq);
        return;
    }

    // Procura pelo jogador no arquivo e atualiza os dados
    while (fgets(linha, sizeof(linha), pont_arq) != NULL) {
        sscanf(linha, "%s %d %d %d", jogador.nome, &jogador.vitorias, &jogador.derrotas, &jogador.pontos);
        if (strcmp(jogador.nome, nomeJogador) == 0) {
            jogador.vitorias++;
        }
        // Escreve a linha no arquivo temporário
        fprintf(temp_arq, "%s %d %d %d\n", jogador.nome, jogador.vitorias, jogador.derrotas, jogador.pontos);
    }

    // Fecha os arquivos
    fclose(pont_arq);
    fclose(temp_arq);

    // Remove o arquivo original
    remove("ranking.txt");
    // Renomeia o arquivo temporário
    rename(temp_nome, "ranking.txt");
}

void adicionarDerrota(const char *nomeJogador) {
    FILE *pont_arq;
    Jogador jogador;
    FILE *temp_arq;
    char linha[MAX_NOME + 20]; // Tamanho máximo da linha no arquivo
    char temp_nome[] = "temp_ranking.txt"; // Nome do arquivo temporário

    // Abre o arquivo original no modo leitura
    pont_arq = fopen("ranking.txt", "r");
    if (pont_arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Abre um arquivo temporário no modo escrita
    temp_arq = fopen(temp_nome, "w");
    if (temp_arq == NULL) {
        printf("Erro ao abrir o arquivo temporário.\n");
        fclose(pont_arq);
        return;
    }

    // Procura pelo jogador no arquivo e atualiza os dados
    while (fgets(linha, sizeof(linha), pont_arq) != NULL) {
        sscanf(linha, "%s %d %d %d", jogador.nome, &jogador.vitorias, &jogador.derrotas, &jogador.pontos);
        if (strcmp(jogador.nome, nomeJogador) == 0) {
            jogador.derrotas++;
        }
        // Escreve a linha no arquivo temporário
        fprintf(temp_arq, "%s %d %d %d\n", jogador.nome, jogador.vitorias, jogador.derrotas, jogador.pontos);
    }

    // Fecha os arquivos
    fclose(pont_arq);
    fclose(temp_arq);

    // Remove o arquivo original
    remove("ranking.txt");
    // Renomeia o arquivo temporário
    rename(temp_nome, "ranking.txt");
}

void mostrarRanking(){      
    
    FILE *pont_arq;

     system("cls");
     printf("\n ######- Ranking de Jogadores -######\n");
     printf("  \n");
     printf(" NOME - VITORIAS - DERROTAS - PONTOS \n");
     printf("  \n");
     printf(" ");

    char texto_str[999];

    //abrindo o arquivo_frase em modo "somente leitura"
    pont_arq = fopen("ranking.txt","r");

    while(fgets(texto_str, 20, pont_arq) != NULL)
    printf("%s \n ", texto_str);

  fclose(pont_arq);
}

int main() {
    /*JOGO*/
    /* MENU */
    int opcao;
    SetConsoleTitle("Game"); // Título do programa
    do{
        inicio:
        opcao=0;
        L=2;L2=2;b=2;
        system("cls"); // Limpar a tela dos comandos anteriores
        system("color 1F"); // Definindo a cor do fundo e a letra no cmd
        printf("Dica: Precione a tecla ESQ a qualquer momento para voltar para o menu principal!");
        /*modificando o valor de co muda a coluna de inicio do menu que pose ser de zero ate 63*/
        /*modificando o valor de L muda a linha de inicio do menu que pode ser de zero ate 20*/
        opcao=0;co=0;/*co é a coluna onde colocar a seta*/
        L=3;/*L é a linha onde fica as opções, mudando as opções p/baixo mude o valor de L igual*/
        L2=L;    /*L2 é onde estava a seta */
        L3=L+4;  /*L3 é a linha final do menu*/
        L4=L;    /*L4 é a linha de inicio do menu*/

        gotoxy(co+5,L);     // co é a coluna de inicio do menu e L é a linha de inico do menu
        printf("1 - JOGAR");
        gotoxy(co+5,L+1);
        printf("2 - RANKING");
        gotoxy(co+5,L+2);
        printf("3 - COMO JOGAR");
        gotoxy(co+5,L+3);
        printf("4 - SOBRE");
        gotoxy(co+5,L+4);
        printf("5 - SAIR\n");

        do{                       /*loop para movimentar a seta*/
            gotoxy(co+2,L);       /*gotoxy posiciona o cursor, o co é a coluna e L é a linha onde imprimir a seta*/
            printf("-%c",16);     /*imprime a seta*/
            gotoxy(5,0);         /*posiciona o cursor fora da tela para ele não ficar piscando*/
            if(kbhit){a=getch();} /*se alguma tecla foi pressionada a igual a tecla*/
            if(a == 80){          /*80 é valor do cactere seta p/baixo do teclado*/
                L2=L;             /*L2 é posição onde estava a seta para apagar senao fica duas setas*/
                L++;              /*L aponta para a nova posição da seta*/
                if(L>L3){L=L4;}   /*L vai de 2 ate 5 pois é onde estão as 4 opções, mudando mude tambem os valores*/
            }                     /*a seta estando no 4 e for movida p/baixo ela vai para a primeira opção*/
            if(a == 72){          /*72 é valor do cactere seta p/cima do teclado*/
                L2=L;             /*L2 é onde estava a seta para apagar*/
                L--;              /*L aponta para a nova posição da seta*/
                if(L<L4){L=L3;}   /*a seta estando no 1 e for movida p/cima ela vai para a ultima opção*/
            }
            if(L!=L2){            /*se a seta for movida */
                gotoxy(co+2,L2);  /*posicione o cursor onde estava a seta*/
                printf("  ");     /*imprime espaços em branco(que sao pretos) em cima da seta para apaga-la*/
                L2=L;             /*L2 igual a nova posição da seta*/
            }
            if(a == 13){          /*se a tecla enter for pressionada*/
                opcao=L-(L4-1);        /*opcao igual a linha onde esta a opção menos um, pois a primeira opção */
                                  /*esta na linha 2*/
            }
        }while(opcao == 0);       /*repete enquanto opcao igual a zero*/

    switch (opcao) {
    case 1:
        system("cls");
        while (a != 27 || a != 13){
        if(kbhit){a=getch();}
        if(a == 27){
        goto inicio;
            }
        }
        
        break;
    case 2:
        system("cls");
        mostrarRanking();
        do{
            if(kbhit){a=getch();}
        }while(a != 27);
        break;
    case 3:
        system("cls");
        do{
            if(kbhit){a=getch();}
        }while(a != 27);
        break;
    case 4:
        system("cls");
        do{
            if(kbhit){a=getch();}
        }while(a != 27);
        break;
    case 5:
        system("cls");
        printf("Voce pediu para sair, fechando programa.");
        gotoxy(0,35);

        for(a=0;a<5;a++){
            printf(".");
            gotoxy(0,30);
            Sleep(1000);
        }
        printf("!\n\n");
		exit(0);
    default:
        system("cls");
        printf("Você deve escolher uma opção válida\n");
        printf("Precione qualquer tecla para voltar ao menu\n");
        system("pause");
        goto inicio;
        }
    }while(opcao!=5);

    return 0;
}