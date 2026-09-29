#include <cs50.h>
#include <math.h>
#include <stdio.h>

int sum_digits(int checksum, long number);
int get_first_two_digits(long number);
void check_card(long card);

int main(void) {
  long credit_card_number = get_long("Nubmer: ");
  check_card(credit_card_number);
}

void check_card(long card) {
  if (sum_digits(1, card) % 10 == 0) {
    int first_two_digits = get_first_two_digits(card);
    int digit_number = (int)log10(card) + 1;
    if ((first_two_digits == 34 || first_two_digits == 37) &&
        digit_number == 15) {
      printf("AMEX\n");
    } else if (first_two_digits <= 55 && first_two_digits >= 51 &&
               digit_number == 16) {
      printf("MASTERCARD\n");
    } else if (first_two_digits <= 49 && first_two_digits >= 40 &&
               (digit_number == 16 || digit_number == 13)) {
      printf("VISA\n");
    } else {
      printf("INVALID\n");
    }
  } else {
    printf("INVALID\n");
  }
}

int get_first_two_digits(long number) {
  int extra_digit = 11;
  int first_digits = 1;
  while (!(first_digits < 100 && first_digits > 9)) {
    if (first_digits == 0) {
      break;
    }
    first_digits = (int)(number / pow(10, extra_digit));
    extra_digit++;
  }
  return first_digits;
}

int sum_digits(int checksum, long number) {
  int current_digit;
  int sum_of_digits = 0;
  int digit_positon = -1;
  int multiplier = 1;
  if (checksum == 1) {
    multiplier = 2;
  }
  while (number > 0) {
    current_digit = number % 10;
    if (digit_positon % 2 == 0) {
      sum_of_digits += sum_digits(0, (current_digit * multiplier));
    } else {
      sum_of_digits += (current_digit);
    }
    number /= 10;
    digit_positon--;
  }
  return sum_of_digits;
}
