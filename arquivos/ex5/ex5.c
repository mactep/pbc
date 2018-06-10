#include <stdio.h>

int main(int argc, char const* argv[])
{
  FILE *entrada, *saida;

  entrada = fopen("./matrizes.txt", "r");
  if (entrada == NULL) {
    printf("Erro ao abrir o arquivo de entrada\n");
      return 1;
  }

  int matrizes[5][4][4];

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        fscanf(entrada, "%d", &matrizes[i][j][k]);
      }
    }
  }

  saida = fopen("./transp.txt", "w");

  int aux;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        fprintf(saida, "%d ", matrizes[i][k][j]);
      }
      fprintf(saida, "\n");
    }
    fprintf(saida, "\n");
  }

  fclose(saida);

  return 0;
}
