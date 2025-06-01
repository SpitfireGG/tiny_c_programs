#include <ctype.h>
#include <stdio.h>

int main() {

  char ch;
  while ((ch = getchar()) != EOF) {
    int shift = 'F' - 'A';
    putchar(isalpha(ch)
                ? ((ch | 0x20) - 'a' + shift) % 26 + (ch & 0x20 ? 'a' : 'A')
                : ch);
  }

  return 0;
}
