#include <ctype.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main(void) {
  int c;
  struct termios oldt, newt;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  puts("Enter some characters:");
  while ((c = getc(stdin)) != EOF) {
    if (isalpha(c)) {
      putc('@', stdout);
      continue;
    }
    if (isdigit(c)) {
      putc('#', stdout);
      continue;
    }
    putc('.', stdout);
  }
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return 0;
}
