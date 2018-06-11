#include <stdio.h>
#include <stdlib.h>

int **cria_matriz_chave() {
  FILE *entrada;
  int N;

  entrada = fopen("batalhaNaval.txt", "r");
  if (entrada == NULL) {
    printf("Erro ao ler arquivo de entrada\n");
    exit(1);
  }
  fscanf(entrada, "%d", &N);
  int **campo = (int **)malloc(N * sizeof(int*));
  for (int i = 0; i < N; i++) {
    campo[i] = (int *)malloc(N * sizeof(int));
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
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

//TODO: melhorar essa funcao
void imprime_jogo(int tam, int matriz[tam][tam]) {
  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
  printf("----------\n");
}

int main(int argc, char const* argv[])
{
  int **campo = cria_matriz_chave();
  return 0;
}
