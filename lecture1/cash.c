#include <cs50.h>
#include <stdio.h>

int main(void) {
  int quarter = 25;
  int dime = 10;
  int nickel = 5;
  int penny = 1;
  int number_of_coins = 0;
  int change;
  do {
    change = get_int("Change owed: ");
  } while (change < 0);

  number_of_coins += (change / quarter);
  change -= ((change / quarter) * quarter);

  number_of_coins += (change / dime);
  change -= ((change / dime) * dime);

  number_of_coins += (change / nickel);
  change -= ((change / nickel) * nickel);

  number_of_coins += (change / penny);
  change -= ((change / penny) * penny);

  printf("%i\n", number_of_coins);
}
