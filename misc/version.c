#include <stdio.h>

int main() {
#if defined(__STDC_VERSION__)
    printf("__STDC_VERSION__ is defined.\n");
    if (__STDC_VERSION__ >= 202311L) {
        printf("C Standard: C23 (or later)\n");
    } else if (__STDC_VERSION__ >= 201710L) {
        printf("C Standard: C18\n");
    } else if (__STDC_VERSION__ >= 201112L) {
        printf("C Standard: C11\n");
    } else if (__STDC_VERSION__ >= 199901L) {
        printf("C Standard: C99\n");
    } else {
        printf("C Standard\n");
    }
#else
#endif
    return 0;
}
