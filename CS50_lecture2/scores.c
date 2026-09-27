#include <cs50.h>
#include <stdio.h>
float average(int length, int numbers[]);
int main(void) {
  int score1 = 72;
  int score2 = 73;
  int score3 = 33;

  printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
  // when using (float) the decimal number wasn't accurate and when using 3.0
  // the result was more accurate.
  //
  // #ARRAYS
  const int N = 3;
  int scores[N];
  for (int i = 0; i < N; i++) {
    scores[i] = get_int("Score: ");
  }
  printf("Average: %f\n", average(N, scores));
}
float average(int length, int numbers[]) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += numbers[i];
  }
  return sum / (float)length;
}