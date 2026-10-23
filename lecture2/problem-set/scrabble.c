#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int calculate_score(string word);

int main(void) {
  string player1 = get_string("Player 1: ");
  string player2 = get_string("Player 2: ");
  int score1 = calculate_score(player1);
  int score2 = calculate_score(player2);
  if (score1 > score2) {
    printf("Player 1 wins!\n");
  } else if (score2 > score1) {
    printf("Player 2 wins!\n");
  } else {
    printf("Tie!\n");
  }
}

int calculate_score(string word) {
  const int points[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
  int score = 0;
  for (int i = 0; i < strlen(word); i++) {
    char lower_char = tolower(word[i]);
    if (lower_char >= 'a' && lower_char <= 'z') {
      score += (points[lower_char - 97]);
    }
  }
  return score;
}