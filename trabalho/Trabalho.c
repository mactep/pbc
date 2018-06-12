#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int **le_matriz_chave(int *tam) {
  FILE *entrada;

  entrada = fopen("batalhaNaval.txt", "r");
  if (entrada == NULL) {
    printf("Erro ao ler arquivo de entrada\n");
    exit(1);
  }
  fscanf(entrada, "%d", tam);
  int **campo = (int **)malloc(*tam * sizeof(int*));
  for (int i = 0; i < *tam; i++) {
    campo[i] = (int *)malloc(*tam * sizeof(int));
  }

  for (int i = 0; i < *tam; i++) {
    for (int j = 0; j < *tam; j++) {
      fscanf(entrada, "%d", &campo[i][j]);
    }
  }
  return campo;
}

int **cria_matriz_vazia(int tam) {
  int **m = (int **)malloc(tam * sizeof(int*));
  for (int i = 0; i < tam; i++) {
    m[i] = (int *)malloc(tam * sizeof(int));
  }
  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      m[i][j] = 0;
    }
  }
  return m;
}

void imprime_jogo(int tam, int **matriz) {
  for (int i = 0; i < tam; i++) {
    if (i == tam/2) {
      for (int k = 0; k < 2*tam; k++) {
        printf("-");
      }
      printf("\n");
    }
    for (int j = 0; j < tam; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

/*typedef struct {
  int x, y;
} posicao;*/

void pega_jogada(int jogador, int tam, int **campo, int **chave) {
  //posicao p;
  int x = -1;
  int y = -1;
  while (x == -1 || y == -1) {
    printf("Informe um valor para X: ");
    scanf("%d", &x);

    printf("Informe um valor para Y: ");
    scanf("%d", &y);

    if (x < 0 || y < 0 || x >= tam || y >= tam) {
      printf("Posicao fora do campo. Informe outra jogada\n");
      x = -1;
    } else if (jogador == 1 && y < tam/2) {
      printf("Posicao no proprio campo. Informe outra jogada\n");
      y = -1;
    } else if (jogador == -1 && y >= tam/2) {
      printf("Posicao no proprio campo. Informe outra jogada\n");
      y = -1;
    } else if (campo[x][y] == 1) {
      printf("Posicao ja descoberta. Informe outra jogada\n");
      x = -1;
      y = -1;
    } else {
      printf("So jogada top, Rogerinho!\n");
      printf("Posicao informada: (%d, %d)\n", x, y);
    }
  }
  if (chave[x][y] == 1) {
    printf("Acertou mais navio que Kamikaze em Pearl Harbor!\n");
    campo[x][y] = 1;
  } else {
    printf("Errou feio, errou rude!\n");
  }
  /*return p;*/
}

int main(int argc, char const* argv[])
{
  int tamanho;
  //jogador_atual vai ser 1(primeiro) e -1(segundo)
  int jogador_atual = 1;
  int jogando = 1;

  int **chave = le_matriz_chave(&tamanho);
  printf("%d\n", tamanho);

  int **campo = cria_matriz_vazia(tamanho);
  imprime_jogo(tamanho, campo);

  while (jogando) {
    system("clear");
    printf("Jogando agora: jogador %d\n", jogador_atual);
    imprime_jogo(tamanho, campo);
    pega_jogada(jogador_atual, tamanho, campo, chave);
    sleep(2);
    jogador_atual *= -1;
  }
  return 0;
}
