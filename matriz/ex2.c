#include <stdio.h>

int positivos(int lin, int col, int matriz[lin][col]) {
  int pos = 0;
  for (int i = 0; i < lin; i++) {
    for (int j = 0; j < col; j++) {
      if (matriz[i][j] > 0) {
        pos++;
      }
    }
  }
  return pos;
}

int main(int argc, char const* argv[])
{
  int A[3][3], B[3][3], C[3][3], D[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d\n", &A[i][j]);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d\n", &B[i][j]);
    }
  }
  if (positivos(3, 3, A) > positivos(3, 3, B)) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        C[i][j] = A[i][j] - B[i][j];
      }
    }
  } else {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        C[i][j] = B[i][j] - A[i][j];
      }
    }
  }
  printf("\n\n\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
  return 0;
}
