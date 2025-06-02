#include <stdint.h>
#include <stdio.h>

#include <stdio.h>

// define some generic printings

#define PRINT_VAR(X)                                                                               \
    _Generic((X),                                                                                  \
        int: "%d\n",                                                                               \
        float: "%f\n",                                                                             \
        double: "%lf\n",                                                                           \
        char*: "%s\n",                                                                             \
        void*: "%p\n",                                                                             \
        default: "Unsupported type\n"),                                                            \
        (X)

int main() {

    uint32_t abs = 10;
    uint32_t* ptr = &abs;

    printf("%p\n",
           (void*)ptr); // print out the memory address from ptr and
                        // then pass it as input below

    int* my_ptr;
    printf("Enter a hexadecimal address (e.g., 0x7ffeefbff53c): ");
    scanf("%p", &my_ptr); // Reads a pointer value

    printf("You entered the address: %p\n", (void*)my_ptr);

    my_ptr = (int*)my_ptr;
    printf("you entered %d\n", *my_ptr);

    int chars_printed;
    printf("Hello, World!%n\n", &chars_printed);
    printf("Characters printed: %d\n",
           chars_printed); // prints 13 %n prints out nm of characters in the string including the
                           // null term

    int i = 10;
    float f = 3.14f;
    double d = 2.718;
    char* s = "Hello";
    int* p = &i;

    printf("Integer: ");
    printf(PRINT_VAR(i));

    printf("Float: ");
    printf(PRINT_VAR(f));

    printf("Double: ");
    printf(PRINT_VAR(d));

    printf("String: ");
    printf(PRINT_VAR(s));

    putchar('\n');
    putchar('\n');

    printf("|%10d|\n", 192);
    printf("|%-10d|\n", 192);

    printf("%+d\n", 50);
    printf("%+d\n", -50);

    printf("%#o\n", 10);
    printf("%#x\n", 255);
    printf("%#X\n", 255);
    printf("%#f\n", 5.0);

    int width = 10;
    printf("|%*d|\n", width, 123);

    return 0;
}
