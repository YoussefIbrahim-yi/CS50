#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int number;
  struct node *next;
} node;

int main(void) {
  node *list = NULL;
  for (int i = 0; i < 3; i++) {
    node *n = malloc(sizeof(node));
    n->number = get_int("Number: ");
    // ***** this null is to make sure that the pointee isn't garbage value
    // *****
    n->next = NULL;

    // prepend node to list
    n->next = list;
    list = n;
  }
  // NO NEED TO FOR MALLOC JUST MAKE *ptr POINT TO THE LIST
  // node *ptr = malloc(sizeof(node));
  node *ptr = list;
  while (ptr != NULL) {
    printf("%i\n", ptr->number);
    ptr = ptr->next;
  }
  for (node *ptr = list; ptr != NULL; ptr = ptr->next) {
    printf("%i\n", ptr->number);
  }
  return 0;
}