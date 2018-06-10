#include <stdio.h>

int main(int argc, char const* argv[])
{

  FILE *entrada, *aprovados, *reprovados;
  char nome[10];
  int media;

  aprovados = fopen("./aprovados.txt", "w");
  if (aprovados == NULL) {
    printf("Erro ao abrir o arquivo dos aprovados\n");
    return 1;
  }
  reprovados = fopen("./reprovados.txt", "w");
  if (reprovados == NULL) {
    printf("Erro ao abrir o arquivo dos reprovados\n");
    return 1;
  }

  char entradas[3][11] = {"bsi.txt", "comp.txt", "engmec.txt"};

  for (int i = 0; i < 3; i++) {
    entrada = fopen(entradas[i], "r");
    if (entrada == NULL) {
      printf("Erro ao abrir o arquivo de entrada\n");
      return 1;
    }

    while (!feof(entrada)) {
      fscanf(entrada, "%s %d", nome, &media);
      /*printf("%s %d\n", nome, media);*/
      if (media >= 8) {
        printf("%s esta aprovado com media %d\n", nome, media);
        fprintf(aprovados, "%s\n", nome);
      } else {
        fprintf(reprovados, "%s\n", nome);
      }
    }
    fclose(entrada);
  }
  fclose(aprovados);
  fclose(reprovados);
  return 0;
}
