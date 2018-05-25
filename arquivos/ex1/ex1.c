#include <stdio.h>

float acima_do_peso(float peso, float altura) {
  float peso_ideal = (altura - 1) * 100;
  if (peso > peso_ideal) {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char const* argv[])
{
  FILE *entrada, *saida;

  char nome[10];
  int idade;
  float peso, altura;

  entrada = fopen("./paciente.txt", "r");
  if (entrada == NULL) {
    printf("Erro ao abrir o arquivo de entrada\n");
    return 1;
  }

  saida = fopen("./acimadopeso.txt", "w");
  if (saida == NULL) {
    printf("Erro ao abrir o arquivo de saida\n");
    return 1;
  }
  fclose(saida);
  while (!feof(entrada)) {
    fscanf(entrada, "%s %d %f %f\n", nome, &idade, &peso, &altura);
    printf("%s %d %.2f %.2f\n", nome, idade, peso, altura);
    if (acima_do_peso(peso, altura)) {
      fprintf(saida, "%s %d\n", nome, idade);
    }
  }
  fclose(entrada);
  return 0;
}
