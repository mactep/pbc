#include <stdio.h>
#include <stdlib.h>

char **cria_jogo() {
  char **jogo;

  jogo = (char **)malloc(3 * sizeof(char*));
  for(int i = 0; i < 3; i++) {
    jogo[i] = (char *)malloc(3 * sizeof(char));
    for(int j = 0; j < 3; j++) {
      jogo[i][j] = 32;
    }
  }
  return jogo;
}

void imprime_jogo(char **jogo){
  system("clear");
  printf("JOGO  DA VELHA\n\n");
  printf("   [0] [1] [2]\n");
  printf("[0] %c | %c | %c\n", jogo[0][0], jogo[0][1], jogo[0][2]);
  printf("   -----------\n");
  printf("[1] %c | %c | %c\n", jogo[1][0], jogo[1][1], jogo[1][2]);
  printf("   -----------\n");
  printf("[2] %c | %c | %c\n", jogo[2][0], jogo[2][1], jogo[2][2]);
}

void pega_jogada(int *jogador, char **jogo) {
  int x = 3, y = 3;

  while(x < 0 || x > 2 || y < 0 || y > 2 || jogo[y][x] != 32) {
    printf("Jogador %d, escolha uma linha e uma coluna (0 a 2):\n", *jogador);
    scanf("%d %d", &x, &y);
  }
  if(*jogador) {
    jogo[y][x] = 79;
  }
  else {
    jogo[y][x] = 88;
  }
}

int main() {
  char **tabuleiro;
  int jogador_atual = 1;

  tabuleiro = cria_jogo();
  imprime_jogo(tabuleiro);
  for(int i = 0; i < 9; i++) {
    pega_jogada(&jogador_atual, tabuleiro);
    imprime_jogo(tabuleiro);
    jogador_atual = !jogador_atual;
  }
  return 1;
}
