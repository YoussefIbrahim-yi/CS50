#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  string s = get_string("Input:  ");
  printf("Output: ");
  // don't use function call in for loop condition, inefficient!!
  for (int i = 0, n = strlen(s); i < n; i++) {
    printf("%c", s[i]);
  }
  printf("\n");
}