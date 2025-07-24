#include "double_hash.h"
#include <stdio.h>
#include <stdlib.h>
#define PRINT_CONTROL 1
int abs(int num)
{
    int tmp = num >> 31;
    return (num + tmp) ^ tmp;
}

int hash1(int key)
{
    return abs(key) % TABLE_SIZE;
}

int hash2(int key)
{
    return 1 + abs(key) % (TABLE_SIZE - 1);
}
// create and initialize a hashtable
hash_item_t *hashtable_create()
{
    hash_item_t *ht = malloc(TABLE_SIZE * sizeof(hash_item_t));
    for (int i = 0; i < TABLE_SIZE; ++i)
        ht[i].key = EMPTY;
    return ht;
}

// search for the a hash item matching the key
hash_item_t *hashtable_search(hash_item_t *ht, int key)
{
    int hv1 = hash1(key);
    int hv2 = hash2(key);
    int start = (hv1 + hv2) % TABLE_SIZE;
    int ind = start;

    do
    {
        if (ht[ind].key == EMPTY || ht[ind].key == key)
            return &ht[ind];
        ind = (ind + hv2) % TABLE_SIZE;
    } while (ind != start);

    return NULL;
}

// insert a hash item to hashtable
void hashtable_insert(hash_item_t *ht, int key, int value)
{
    int hv1 = hash1(key);
    int hv2 = hash2(key);
    int start = (hv1 + hv2) % TABLE_SIZE;
    int ind = start;
    int first_deleted = -1;
    do
    {
        if (ht[ind].key == EMPTY)
            break;
        else if (ht[ind].key == key)
        {
            if (PRINT_CONTROL)
                printf("[INFO] INSERT %d failed since it is duplicated\n", key);
            return;
        }
        else if (ht[ind].key == DELETED && first_deleted == -1)
            first_deleted = ind;

        ind = (ind + hv2) % TABLE_SIZE;
    } while (ind != start);
    int target_pos = (first_deleted == -1) ? ind : first_deleted;
    ht[target_pos].key = key;
    ht[target_pos].value = value;
}

void hashtable_remove(hash_item_t *ht, int key)
{
    hash_item_t *tmp = hashtable_search(ht, key);
    /* if the hash item doesn't exist in hashtable */
    if (!tmp || tmp->key != key)
    {
        if (PRINT_CONTROL)
            printf("[INFO] REMOVE %d failed since the item doesn't exist\n", key);
    }
    /* delete the key */
    tmp->key = DELETED;
    return;
}

// Iterate through the hashtable and print every item.
void hashtable_print_table(hash_item_t *ht)
{
    for (int i = 0; i < TABLE_SIZE; ++i)
        if (ht[i].key != EMPTY && ht[i].key != DELETED)
            printf("(key:%d, value:%d)\n", ht[i].key, ht[i].value);
    return;
}