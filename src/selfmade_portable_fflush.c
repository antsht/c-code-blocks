#include <stdio.h>

#define BUF_SIZE 1024

int main(void) {
  int number = 0;
  puts("Enter a number:");
  scanf("%d", &number);
  printf("You entered: %d\n", number);
  char c;
  while ((c = getchar()) != '\n' && c != EOF) {
      ;
  }

  char str[BUF_SIZE];
  puts("Enter a string:");
  fgets(str, BUF_SIZE, stdin);
  printf("You entered: %s\n", str);

  return 0;
}
