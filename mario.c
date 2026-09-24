//    #  #
//   ##  ##
//  ###  ###
// ####  ####

#include <stdio.h>

void print_half_row(int n);
void print_space(int n);
void print_pyramids_blocks(int n);

int main(void) {
  int n;
  do {
    printf("Enter Pyramid's Height: ");
    scanf("%i", &n);
  } while (n < 1 || n > 8);
  print_pyramids_blocks(n);
}

void print_half_row(int n) {
  for (int i = 0; i < n; i++) {
    printf("#");
  }
}
void print_space(int n) {
  for (int i = 0; i < n; i++) {
    printf(" ");
  }
}
void print_pyramids_blocks(int n) {
  for (int height = 0; height < n; height++) {
    print_space(n - height);
    print_half_row(height + 1);
    printf("  ");
    print_half_row(height + 1);
    printf("\n");
  }
}