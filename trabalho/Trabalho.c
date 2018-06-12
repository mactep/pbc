#include <stdio.h>
#include <stdlib.h>

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

typedef struct {
  int x, y;
} posicao;

posicao pega_jogada(int tam) {
  posicao p;
  p.x = -1;
  p.y = -1;
  while (p.x == -1 || p.x < 0 || p.x >= tam) {
    printf("Informe um valor para X: ");
    scanf("%d", &p.x);
  }
  while (p.y == -1 || p.y < 0 || p.y >= tam) {
    printf("Informe um valor para Y: ");
    scanf("%d", &p.y);
  }
  return p;
}

int main(int argc, char const* argv[])
{
  int tamanho;

  int **chave = le_matriz_chave(&tamanho);
  printf("%d\n", tamanho);

  int **campo = cria_matriz_vazia(tamanho);
  imprime_jogo(tamanho, campo);

  posicao eoq = pega_jogada(tamanho);
  return 0;
}
