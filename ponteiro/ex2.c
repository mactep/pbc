#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[])
{
  int N;

  scanf("%d", &N);
  int *vetozao = (int *)malloc(N * sizeof(int));

  for (int i = 0; i < N; i++) {
    scanf("%d", &vetozao[i]);
  }

  for (int i = 0; i < N; i++) {
    printf("%d ", vetozao[i]);
  }
  printf("\n");
  return 0;
}
