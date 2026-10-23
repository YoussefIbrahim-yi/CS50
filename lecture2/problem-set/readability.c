#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int calculate_grade(string s);

int main(void) {
  string text = "Harry Potter was a highly unusual boy in many ways. For one "
                "thing, he hated the summer holidays more than any other time "
                "of year. For another, he really wanted to do his homework, "
                "but was forced to do it in secret, in the dead of the night. "
                "And he also happened to be a wizard.";
  int coleman_liau_index = calculate_grade(text);
  if (coleman_liau_index >= 16) {
    printf("Grade 16+\n");
  } else if (coleman_liau_index < 1) {
    printf("Before Grade 1\n");
  } else {
    printf("Grade %i\n", coleman_liau_index);
  }
}

int calculate_grade(string s) {
  int sentence_count = 0;
  int word_count = 1;
  int letter_count = 0;
  for (int i = 0; i < strlen(s); i++) {
    char current_char = s[i];
    if (tolower(current_char) >= 'a' && tolower(current_char) <= 'z') {
      letter_count++;
    } else if (current_char == ' ') {
      word_count++;
    } else if (current_char == '?' || current_char == '.' ||
               current_char == '!') {
      sentence_count++;
    }
  }
  float index = 0.0588 * letter_count / word_count * 100 -
                0.296 * sentence_count / word_count * 100 - 15.8;
  printf("Index: %f\n", index);
  printf("words number: %i\n", word_count);
  return (int)round(index);
}