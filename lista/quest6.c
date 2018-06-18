#include <stdio.h>
#include <stdlib.h>

float *cria_vetor(int N) {
  float *vet;
  vet = (float *)malloc(N * sizeof(float));

  for (int i = 0; i < N; i++) {
    scanf("%f", &vet[i]);
  }

  return vet;
}

int main(int argc, char const* argv[])
{
  int N;

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &N);

  float *vetor = cria_vetor(N);

  for (int i = 0; i < N; i++) {
    printf("%.2f ", vetor[i]);
  }
  printf("\n");
  return 0;
}
