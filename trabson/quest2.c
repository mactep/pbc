#include <stdio.h>

void imprime_vetor(int tam, int vet[tam]) {
  if (vet[0] <= vet[tam - 1]) {
    printf("O vetor crescente e: ");
    for (int i = 0; i < tam; i++) {
      printf("%d ", vet[i]);
    }
  } else {
    printf("O vetor decrescente e: ");
    for (int i = 0; i < tam; i++) {
      printf("%d ", vet[i]);
    }
  }
}

int main(int argc, char const *argv[]) {
  int vetNums[4], vetCrescente[4], vetDecrescente[4];
  for (int i = 0; i < 4; i++) {
    scanf("%d", &vetNums[i]);
  }
  // Ordenar os valores aqui. Usar algum dos algoritimos
  int aux;
  return 0;
}
