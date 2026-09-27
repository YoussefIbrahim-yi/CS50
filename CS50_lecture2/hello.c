#include <cs50.h>
#include <stdio.h>
void print_column(int height);

int main(void) {
  int h;
  //   printf("What's the height? ");
  //   scanf("%i", &h);
  string name = get_string("What's you name? ");
  printf("Hello, %s\n", name);
  printf("Hello\n");
  //   print_column(h);
  return 0;
}
void print_column(int height) {
  for (int i = 0; i <= height; i++) {
    printf("#\n");
  }
}
