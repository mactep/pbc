#include "stdio.h"

int fatorial(int n) {
  int fat = 1;
  for (int i = 1; i <= n; i++) {
    fat = fat * i;
  }
  return fat;
}

int main() {
  int a;
  printf("Digite um numero: ");
  scanf("%d", &a);
  printf("O fatorial de %d e: %d\n", a, fatorial(a));
  return 0;
}
