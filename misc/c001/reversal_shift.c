#include <stdio.h>

void bitreversal_chiper();

void bitreversal_chiper() {
  char ch;
  while ((ch = getchar()) != EOF) {
    char lower = (ch | 0x20) - 'a';
    unsigned int rev = ((lower * 0x0202020202ULL & 0x010884422010ULL) % 1023);
    ch = rev + (ch & 0x20 ? 'a' : 'A');
    putchar(ch);
  }
}

int main(void) {
  bitreversal_chiper();
  return 0;
}
