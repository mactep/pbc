#include <stdio.h>

void print_vet(int n, int vetor[n]) {
  for (int i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
}

int repetido(int valor, int tam, int vetor[tam]) {
  for (int i = 0; i < tam; i++) {
    if (valor == vetor[i]) {
      return 1;
    }
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  int vet[10];
  int aux;
  int i = 0;
  while (i < 10) {
    printf("Digite um valor pro vetor[%d]: ", i);
    scanf("%d", &aux);
    if (repetido(aux, 10, vet)) {
      printf("Este valor ja esta contido no vetor, digite outro\n");
    } else {
      vet[i] = aux;
      i++;
    }
  }
  for (int i = 0; i < 10; i++) {
    printf("%d ", vet[i]);
  }
  printf("\n");
  return 0;
}
