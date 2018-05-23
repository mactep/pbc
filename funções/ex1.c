#include "stdio.h"

int primo(int n) {
  for (int i = 1; i < n; i++) {
    if (n % i) {
      continue;
    }
    else {
      return 0;
    }
  }
  return 1;
}

int main() {
  int a;
  printf("Digite um numero: ");
  scanf("%d", &a);
  printf("O numero %d e primo: %d\n", a, primo(a));
  return 0;
}
