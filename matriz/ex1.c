#include <stdio.h>

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
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      C[i][j] = A[i][j] + B[i][j];
      D[i][j] = A[i][j] - B[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", D[i][j]);
    }
    printf("\n");
  }
  return 0;
}
