#include <ctype.h>
#include <stdio.h>

void xorshift_chiper(int shift);

void xorshift_chiper(int shift) {

  char ch;
  while ((ch = getchar()) != EOF) {
    ch = isalpha(ch) ? ((ch ^ 0x1F) >> shift | (ch << 7)) : ch;
    putchar(ch);
  }
}

int main(void) {
  xorshift_chiper(1);
  return 0;
}
