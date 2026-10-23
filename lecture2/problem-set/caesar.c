#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void cipher(int key, string text);
int only_digits(string s);

int main(int argc, string argv[]) {
  if (argc != 2 || only_digits(argv[1]) == 1) {
    printf("Usage: ./caesar key");
    return 1;
  }
  string text = get_string("plaintext: ");
  int key = atoi(argv[1]);
  cipher(key, text);
  return 0;
}
int only_digits(string s) {
  int s_length = strlen(s);
  for (int i = 0; i < s_length; i++) {
    if (!isdigit(s[i])) {
      return 1;
    } else {
      continue;
    }
  }
  return 0;
}
void cipher(int key, string text) {
  printf("plaintext:  %s\n", text);
  printf("ciphertext: ");
  int text_length = strlen(text);
  for (int i = 0; i < text_length; i++) {
    if (isupper(text[i])) {
      printf("%c", (text[i] - 'A' + key) % 26 + 'A');
    } else if (islower(text[i])) {
      printf("%c", (text[i] - 'a' + key) % 26 + 'a');
    } else {
      printf("%c", text[i]);
    }
  }
  printf("\n");
}
