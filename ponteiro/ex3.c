#include <stdio.h>
#include <stdlib.h>

void verifica(int N, int v[N], int *min, int *max) {
  *min = v[0];
  *max = v[0];
  for (int i = 0; i < N; i++) {
    if (*max < v[i]) {
      *max = v[i];
    }
    if (*min > v[i]) {
      *min = v[i];
    }
  }
}

int main(int argc, char const* argv[])
{
  int N, min, max;

  scanf("%d", &N);
  int *vetozao = (int *)malloc(N * sizeof(int));

  for (int i = 0; i < N; i++) {
    scanf("%d", &vetozao[i]);
  }

  verifica(N, vetozao, &min, &max);

  for (int i = 0; i < N; i++) {
    printf("%d ", vetozao[i]);
  }

  printf("\nmax: %d\nmin: %d\n", max, min);
  return 0;
}
