#include <stdio.h>

int main(void){
    char first_name[50];
    printf("Enter your first name: ");
    scanf("%49s",first_name);
    printf("hello, %s\n",first_name);
    return 0;
}