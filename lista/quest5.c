#include <stdio.h>

void calcula(float x, float y, char c, float *resultado) {
  if (c == '+') {
    *resultado = x + y;
  } else if (c == '-') {
    *resultado = x - y;
  } else if (c == '/') {
    *resultado = x / y;
  } else {
    *resultado = x * y;
  }
}

int main(int argc, char const* argv[])
{
  float x, y, resultado;
  char c;

  scanf("%f %c %f", &x, &c, &y);

  calcula(x, y, c, &resultado);

  printf("%.2f\n", resultado);

  return 0;
}
