#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  string name;
  string number;
} person;
int main(void) {
  person people[3];
  people[0].name = "kelly";
  people[0].number = "42324242";
  people[1].name = "dave";
  people[1].number = "254436234";
  people[2].name = "john";
  people[2].number = "346534737";
}