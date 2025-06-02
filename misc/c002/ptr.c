#include <stdint.h>
#include <stdio.h>

int main(void) {

    uint32_t a = 1000;
    uint32_t* ab = &a;
    void* ptr = &a;

    char* str = "help me point to the second index";

    printf("%p\n", (void*)ab);
    printf("%d\n", *(int*)ptr);
    printf("%d\n", ab[1]); // prints out random junk

    printf("%d\n", *ab);

    printf("%d\n", *(ab + 1));

    printf("%c\n", str[(~0) * (~0)]); // wow this does something intersting right ???

    printf("%c\n", *(str -= ~0)); // this one too

    return 0;
}
