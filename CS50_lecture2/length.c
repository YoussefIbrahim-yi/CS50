#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  string name = get_string("Name: ");
  int array_length = 0;
  while (name[array_length] != '\0') {
    array_length++;
  }
  printf("%i\n", array_length);
  printf("%i\n", strlen(name));
}