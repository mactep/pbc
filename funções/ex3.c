#include "stdio.h"

int algarismos(long int n) {
  int alg = 0;
  while (n > 0) {
    n = n / 10;
    alg++;
  }
  return alg;
}

int main() {
  long int a;
  printf("Digite um numero: ");
  scanf("%ld", &a);
  printf("O numero %ld possui %d algarismo(s)\n", a, algarismos(a));
  return 0;
}
