#include <stdio.h>

int main(void) {

  // int i = 3;
  // while(i > 0){
  //     printf("Meow\n");
  //     i--;
  // }
  // for( int i = 3; i>0; i--){
  //     printf("Meow\n");
  // }

  //   int n;
  //   while (n < 0) {
  //     printf("What's n? ");
  //     scanf("%d", &n);
  //   }
  //   for (int i = 0; i < n; i++) {
  //     printf("Meow\n");
  //   }

  int n;
  do {
    printf("What's n? ");
    scanf("%d", &n);
  } while (n < 0);
  for (int i = 0; i < n; i++) {
    printf("Meow\n");
  }
  return 0;
}