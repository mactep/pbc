#include <stdio.h>
#include <math.h>

int imprime_matriz(int lin, int col, int matriz[lin][col]) {
  for (int i = 0; i < lin; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char const* argv[])
{
  int m, n, diag;

  printf("Digite o numero de linhas da matriz: ");
  scanf("%d", &m);
  printf("Digite o numero de colunas da matriz: ");
  scanf("%d", &n);

  int A[m][n];
  printf("Digite os termos da matriz: ");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  if (m > n) {
    diag = n;
  } else {
    diag = m;
  }
  int V[diag][1];
  for (int i = 0; i < diag; i++) {
    V[i][1] = A[i][i];
  }

  printf("\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d", A[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  for (int i = 0; i < diag; i++) {
    printf("%d", V[i][1]);
    printf("\n");
  }
  return 0;
}
