#include <stdio.h>
#include <math.h>

int soma_diag(int lin, int col, int matriz[lin][col]) {
  int diag;
  int soma = 0;
  if (lin > col) {
    diag = col;
  } else {
    diag = lin;
  }
  for (int i = 0; i < diag; i++) {
    soma += matriz[i][col - 1];
    col--;
  }
  return soma;
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
  printf("\n");
  printf("Matriz A:\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d", A[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("A soma da diagonal secundaria da matriz e: %d\n", soma_diag(m, n, A));
  return 0;
}
