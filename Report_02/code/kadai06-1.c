#include <stdio.h>

float function1(float y1) {
  return -0.5 * y1;
}

float function2(float y1, float y2) {
  return 4 - 0.1 * y1 - 0.3 * y2;
}

float eular1(float y0, float h) {
  return y0 + function1(y0) * h;
}

float eular2(float y0, float y1, float h) {
  return y0 + function2(y1, y0) * h;
}

int main(void) {
  float x[5];
  float y1[5];
  float y2[5];
  float h;

  // default value
  h = 0.5;
  x[0] = 0;
  y1[0] = 4;
  y2[0] = 6;

  printf("i  x   y1    y2\n");
  printf("-----------------\n");
  printf("%d %.1f %.2f %.3f\n", 0, x[0], y1[0], y2[0]);
  for (int i = 1; i <= 4; i++)
  {
    x[i] = x[i - 1] + h;
    y1[i] = eular1(y1[i - 1], h);
    y2[i] = eular2(y2[i - 1], y1[i - 1], h);
    printf("%d %.1f %.2f %.3f\n", i, x[i], y1[i], y2[i]);
  }

  return 0;
}