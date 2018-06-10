#include <stdio.h>

void troca(int *a, int *b) {
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

int main(int argc, char const* argv[])
{
  int a, b;

  scanf("%d %d", &a, &b);

  troca(&a, &b);

  printf("%d %d\n", a, b);

  return 0;
}
