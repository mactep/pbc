#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int **le_matriz_chave(int *tam, int *navios) {
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
      *navios += campo[i][j];
    }
  }
  fclose(entrada);
  return campo;
}

int **cria_matriz_vazia(int tam) {
  int **m = (int **)calloc(tam, sizeof(int*));
  for (int i = 0; i < tam; i++) {
    m[i] = (int *)calloc(tam, sizeof(int));
  }
  return m;
}

void imprime_jogo(int tam, int **matriz) {
  printf("   ");
  for (int i = 0; i < tam; i++) {
    printf("[%d]", i);
  }
  printf("\n");
  for (int i = 0; i < tam; i++) {
    if (i == tam/2) {
      for (int k = 0; k < 4*tam; k++) {
        printf("-");
      }
      printf("\n");
    }
    printf("[%d]", i);
    for (int j = 0; j < tam; j++) {
      printf(" %d ", matriz[i][j]);
    }
    printf("\n");
  }
}

typedef struct {
  int x, y;
} posicao;

posicao pega_jogada(int jogador, int tam, int **campo) {
  posicao p;
  p.x = -1;
  p.y = -1;
  while (p.x == -1 || p.y == -1) {
    printf("Informe um valor para X: ");
    scanf("%d", &p.x);

    printf("Informe um valor para Y: ");
    scanf("%d", &p.y);

    if (p.x < 0 || p.y < 0 || p.x >= tam || p.y >= tam) {
      printf("Posicao fora do campo. Informe outra jogada\n");
      p.x = -1;
    } else if (jogador == 0 && p.y < tam/2) {
      printf("Posicao no proprio campo. Informe outra jogada\n");
      p.y = -1;
    } else if (jogador == 1 && p.y >= tam/2) {
      printf("Posicao no proprio campo. Informe outra jogada\n");
      p.y = -1;
    } else if (campo[p.y][p.x] == 1) {
      printf("Posicao ja descoberta. Informe outra jogada\n");
      p.x = -1;
      p.y = -1;
    } else {
      printf("Posicao informada: (%d, %d)\n", p.x, p.y);
    }
  }
  return p;
}

typedef struct {
  int torpedos;
  char nome[10];
  //navios que ele abateu do openente
  int navios_abatidos;
} jogador;

int main(int argc, char const* argv[])
{
  int tamanho;
  int navios = 0;

  int **chave = le_matriz_chave(&tamanho, &navios);

  int jogador_atual = 0;
  jogador jogadores[2] = {{
    .torpedos = (tamanho * tamanho / 2) * 0.7,
    .nome = "j1",
    .navios_abatidos = 0
  }, {
    .torpedos = (tamanho * tamanho / 2) *0.7,
    .nome = "j2",
    .navios_abatidos = 0
  }};

  int **campo = cria_matriz_vazia(tamanho);

  posicao pos;

  while (1) {
    system("clear");
    printf(">>> BATALHA NAVAL <<<\n");
    printf("Navios: %d\n", navios);
    printf("Jogando agora: %s\n", jogadores[jogador_atual].nome);
    printf("Torpedos restantes: %d\n", jogadores[jogador_atual].torpedos);
    printf("Navios abatidos: %d\n\n", jogadores[jogador_atual].navios_abatidos);

    imprime_jogo(tamanho, campo);

    pos = pega_jogada(jogador_atual, tamanho, campo);

    jogadores[jogador_atual].torpedos -= 1;

    if (chave[pos.y][pos.x] == 1) {
      campo[pos.y][pos.x] = 1;

      printf("Voce acertou um navio. ");

      jogadores[jogador_atual].navios_abatidos += 1;

      if (jogadores[jogador_atual].navios_abatidos == navios / 2) {
        printf("\n\n%s venceu: todos os navios inimigos foram abatidos.\n", jogadores[jogador_atual].nome);
        sleep(2);
        break;
      } else if (jogadores[jogador_atual].torpedos == 0) {
        printf("\n\n%s venceu: o oponente nao possui mais torpedos.\n", jogadores[!jogador_atual].nome);
        sleep(2);
        break;
      } else {
        printf("Informe outra coordenada.\n");
      }

      sleep(2);
      continue;
    } else {
      if (jogadores[jogador_atual].torpedos == 0) {
        printf("\n%s venceu: o oponente nao possui mais torpedos.\n", jogadores[!jogador_atual].nome);
        sleep(2);
        break;
      }
      printf("Errou feio, errou rude!\n");
      sleep(2);
    }

    jogador_atual = !jogador_atual;
  }
  return 0;
}
