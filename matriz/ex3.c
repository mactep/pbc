#include <stdio.h>

#define LIN 2
#define COL 2

int main(int argc, char const* argv[])
{
  printf("Digite uma matriz\n");
  int A[LIN][COL], T[COL][LIN];
  for (int i = 0; i < LIN; i++) {
    for (int j = 0; j < COL; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  for (int i = 0; i < COL; i++) {
    for (int j = 0; j < LIN; j++) {
      T[i][j] = A[j][i];
    }
  }
  for (int i = 0; i < LIN; i++) {
    for (int j = 0; j < COL; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
  for (int i = 0; i < COL; i++) {
    for (int j = 0; j < LIN; j++) {
      printf("%d ", T[i][j]);
    }
    printf("\n");
  }
  return 0;
}
