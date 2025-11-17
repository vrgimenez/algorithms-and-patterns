#include <stdlib.h>
#include <stdio.h>

int sum_d(int a, int b) {
    return a+b;
}

// C does not have method overload based on arguments so you need different functions
float sum_f(float a, float b) {
     return a+b;
}

int main(void) {
  printf("Hello in C\n");
  int c1 = sum_d(2,3);
  printf("The result of 2 + 3 is %d\n", c1);
  float c2 = sum_f(2.5f,3.5f);
  printf("The result of 2.5 + 3.5 is %f\n", c2);

  return 1;
}
