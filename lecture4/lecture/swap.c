#include <limits.h>
#include <stdio.h>

void swap(int *a, int *b);

int main(void) {
  int x = 1;
  int y = 2;

  printf("x is %i, y is %i\n", x, y);
  swap(&x, &y);
  printf("x is %i, y is %i\n", x, y);
  printf("Char: %i\nInt: %i\n", sizeof(char), sizeof(int));
  printf("Char: %i\nInt: %i\n", CHAR_BIT, sizeof(int));
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}