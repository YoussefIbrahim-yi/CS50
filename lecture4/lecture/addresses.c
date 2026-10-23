#include <cs50.h>
#include <stdio.h>

int main(void) {
  int n = 50;
  // print the value of n
  printf("%i\n", n);
  // Wrong wat to get address of n
  printf("%i\n", &n);
  // Right wat to get address of n
  printf("%p\n", &n);
  // pointer variable
  int *p = &n;
  printf("%p\n", p);
  // print value of the variable, which it's address stored in p
  printf("%i\n", *p);

  char *s = "HI!";
  // print the address of each char of the string
  printf("%p\n", s);
  printf("%p\n", &s[0]);
  printf("%p\n", &s[1]);
  printf("%p\n", &s[2]);
  printf("%p\n", &s[3]);
  // print the chars using the address of each
  printf("%c\n", *s);
  printf("%c\n", *(s + 1));
  printf("%c\n", *(s + 2));
  printf("%c\n", *(s + 3));
  // print string starting from a this address
  printf("%s\n", s);
  printf("%s\n", (s + 1));
  printf("%s\n", (s + 2));
  printf("%s\n", (s + 3));
}