#ifndef DOUBLE_HASH_H
#define DOUBLE_HASH_H

#include <stdint.h>
#include <limits.h>
#define TABLE_SIZE 100007
#define EMPTY INT_MIN
#define DELETED INT_MAX
typedef struct
{
    int key; // when the key is set to INT_MIN, it means that the hash item is unoccupied now.
    int value;
} hash_item_t;

int hash1(int key);
hash_item_t *hashtable_create();
hash_item_t *hashtable_search(hash_item_t *ht, int key);
void hashtable_insert(hash_item_t *ht, int key, int value);
void hashtable_remove(hash_item_t *ht, int key);
void hashtable_print_table(hash_item_t *ht);

#endif // DOUBLE_HASH_H