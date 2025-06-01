#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main() {

  char buffer[64];
  printf("enter the string or char: ");

  if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    return 1;

  size_t len = strlen(buffer);
  if (buffer[len - 1] == '\n' && len > 0) {
    buffer[len - 1] = '\0';
  }

  for (size_t i = 0; i < len; i++) {
    if (isalpha(buffer[i])) {
      char base = islower(buffer[i]) ? 'a' : 'A';
      buffer[i] = (buffer[i] - base + 13) % 26 + base;
    }
  }
  printf("Rot13: %s\n", buffer);

  return 0;
}
