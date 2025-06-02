#include <stddef.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char* key;
    int value;
} item;

void* linear_search(item* it, size_t size, const char* key);

void* linear_search(item* it, size_t size, const char* key) {

    size_t i;
    for (i = 0; i < size; i++) {
        if (strcmp(it[i].key, key) == 0) {
            return &it[i];
        }
    }
    return NULL;
}

int main(void) {
    item items[] = {{"foo", 10}, {"bar", 20},   {"baz", 30}, {"mogg", 40},
                    {"bob", 11}, {"jane", 100}, {"x", 200}};
    size_t it_num = sizeof(items) / sizeof(item);

    item* found = linear_search(items, it_num, "foo");
    (found) ? printf("found value for key: %d\n", found->value) : printf("key not found\n");

    return 0;
}
