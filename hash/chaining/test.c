#include "chaining.h"
#include <stdio.h>
int main()
{
    Node_t **ht = chaining_create();

    chaining_insert(ht, 1, 0);
    chaining_insert(ht, 3, 1);
    chaining_insert(ht, 5, 2);
    chaining_insert(ht, 1008, 4);
    chaining_insert(ht, 5, 5);
    chaining_insert(ht, 1010, 5);
    chaining_insert(ht, 1010, 7);
    chaining_remove(ht, 1010);
    chaining_remove(ht, 1010);
    chaining_search(ht, 5);
    chaining_remove(ht, 5);
    chaining_search(ht, 5);
    chaining_print_table(ht);
}