#include <stdio.h>

// Prototype
void meow(int n);
int get_n(void);

int main(void) { meow(get_n()); }

void meow(int n) {
  for (int i = 0; i < n; i++) {
    printf("Meow!\n");
  }
}

int get_n(void) {
  int n;
  do {
    printf("Enter a number: ");
    scanf("%d", &n);
  } while (n < 0);
  return n;
}