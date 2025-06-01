#include <ctype.h>
#include <stdio.h>

int main() {

  char ch;
  int shift_by = 'D' - 'A';

  while ((ch = getchar()) != EOF) { // S -> 83
    if (isalpha(ch)) {
      ch += shift_by; // ch -> 83 + 3 => 86
      ch = (ch > 'Z' && ch < 'a') || ch > 'z' ? ch - 26 : ch;
    }
    putchar(ch);
  }

  return 0;
}
