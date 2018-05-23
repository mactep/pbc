#include "stdio.h"

int primo(int n) {
  for (int i = 2; i < n; i++) {
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
  while (1) {
    printf("Digite um numero: ");
    scanf("%d", &a);
    if (a == -1) {
      break;
    }
    printf("O numero %d e primo: %d\n", a, primo(a));
  }
  return 0;
}
