#include "linear_probe.h"
#include <stdio.h>
int main()
{
    hash_item_t *ht = hashtable_create();
    hashtable_insert(ht, 1, 0);

    hashtable_insert(ht, 1, 0);
    hashtable_insert(ht, 3, 1);
    hashtable_insert(ht, 5, 2);
    hashtable_insert(ht, 1008, 4);
    hashtable_insert(ht, 5, 5);
    hashtable_insert(ht, 1010, 5);
    hashtable_insert(ht, 1010, 7);
    hashtable_remove(ht, 1010);
    hashtable_remove(ht, 1010);
    hashtable_remove(ht, 5);
    hashtable_insert(ht, 1010, 10);
    hashtable_print_table(ht);
}