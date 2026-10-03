#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cipher(string key, string text);
int is_num_key(string key);
int is_string_key(string key);
void cipher_num_key(int key, string text);
void cipher_str_key(string key, string text);

int main(int argc, string argv[]) {
  if (argc != 2 ||
      (is_string_key(argv[1]) == -1 && is_num_key(argv[1]) == -1)) {
    return 1;
  }
  string text = get_string("plaintext: ");
  cipher(argv[1], text);
}
void cipher(string key, string text) {
  printf("plaintext:  %s\n", text);
  printf("ciphertext: ");
  if (is_num_key(key) == 0) {
    int key_num = atoi(key);
    cipher_num_key(key_num, text);
  } else if (is_string_key(key) == 0) {
    cipher_str_key(key, text);
  }
}
int is_num_key(string key) {
  int key_length = strlen(key);
  for (int i = 0; i < key_length; i++) {
    if (!isdigit(key[i])) {
      return -1;
    }
  }
  return 0;
}
int is_string_key(string key) {
  int key_length = strlen(key);
  if (key_length != 26) {
    return -1;
  }
  int key_array[26] = {0};
  for (int i = 0; i < key_length; i++) {
    if (!isalpha(key[i])) {
      return -1;
    }
    int index = tolower(key[i]) - 'a';
    if (key_array[index]) {
      return -1;
    }
    key_array[index] = 1;
  }
  return 0;
}

void cipher_num_key(int key, string text) {
  int text_length = strlen(text);
  for (int i = 0; i < text_length; i++) {
    if (isupper(text[i])) {
      printf("%c", (text[i] + key - 'A') % 26 + 'A');
    } else if (islower(text[i])) {
      printf("%c", (text[i] + key - 'a') % 26 + 'a');
    } else {
      printf("%c", text[i]);
    }
  }
  printf("\n");
}
void cipher_str_key(string key, string text) {
  int text_length = strlen(text);
  for (int i = 0; i < text_length; i++) {
    char current_char = text[i];
    if (isupper(current_char)) {
      printf("%c", toupper(key[current_char - 'A']));
    } else if (islower(current_char)) {
      printf("%c", tolower(key[current_char - 'a']));
    } else {
      printf("%c", text[i]);
    }
  }
  printf("\n");
}
