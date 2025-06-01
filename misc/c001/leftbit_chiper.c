#include <ctype.h>
#include <stdio.h>

void leftshift_cipher(int shift) {
  char ch;
  while ((ch = getchar()) != EOF) {

    // <<input>> :  some -> ( s -a ) + 1  = 97 % 26 = 19 ( 10011 )
    //              00010011 << 1 = 00100110 = 38

    ch = isalpha(ch) ? (((ch | 0x20) - 'a' + 1) % 26) << shift | (ch & 0x20)
                     : ch;
    putchar(ch);
  }
}

int main() {
  leftshift_cipher(1);
  return 0;
}
