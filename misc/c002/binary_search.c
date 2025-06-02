#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    int value;
} items;

int comp(const void* a, const void* b);
void* binary_search(items* it, size_t size, const char* key);

int comp(const void* a, const void* b) {
    items* item_a = (items*)a;
    items* item_b = (items*)b;
    return strcmp(item_a->key, item_b->key);
}

void* binary_search(items* it, size_t size, const char* key) {

    size_t low = 0;
    size_t high = size;
    while (low < high) {
        size_t mid = low + (high - low) / 2;
        int cmp = (strcmp(it[mid].key, key));

        if (cmp == 0) {
            return &it[mid];
        }
        if (cmp < 0)
            low = mid + 1;
        else
            high = mid;
    }
    return NULL;
}

int main(void) {

    items its[] = {{"foo", 10}, {"bar", 20},   {"baz", 30}, {"mogg", 40},
                   {"bob", 11}, {"jane", 100}, {"x", 200},  {"boo", 43}};

    qsort(its, sizeof(its) / sizeof(items), sizeof(items), comp);

    size_t it_num = sizeof(its) / sizeof(items);

    items* found = binary_search(its, it_num, "mogg");
    (found) ? printf("found value for key: %d\n", found->value) : printf("key not found\n");

    return 0;
}
