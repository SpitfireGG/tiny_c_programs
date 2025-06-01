#include <ctype.h>
#include <stdio.h>

int main() {

  const char *nato[] = {
      "Alfa",   "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
      "Hotel",  "India",   "Juliett", "Kilo",   "Lima",   "Mike",    "November",
      "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
      "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};

  char phrase[64];
  printf("Enter the phrase: ");
  fgets(phrase, 64, stdin);

  int i;
  char ch;

  for (i = 0; i < 64; i++) {
    ch = toupper(phrase[i]);
    if (isalpha(ch)) {
      printf("%s ", nato[ch - 'A']);
    }
    if (i == 64) {
      break;
    }
  }
  putchar('\n');

  return 0;
}
