#include <stdio.h>
#include <stdlib.h>
#include "chaining.h"
#define PRINT_CONTROL 1
// The insertion function of hashtable using chaining method.
static int get_hash(int key)
{
    return key % CHAINING_TABLE_SIZE;
}

Node_t **chaining_create()
{
    Node_t **ht = calloc(CHAINING_TABLE_SIZE, sizeof(Node_t *));
    return ht;
}
int chaining_insert(Node_t **ht, int key, int value)
{
    int hv = get_hash(key);
    // check whether the key already exists in hashtable.
    Node_t *p = ht[hv];
    while (p)
    {
        // return -1 when the key is duplicate.
        if (p->key == key)
        {
            if (PRINT_CONTROL)
                printf("[INFO] INSERT %d is duplicate \n", key);
            return -1;
        }
        p = p->next;
    }

    // insert the new node at the head.
    Node_t *new_node = malloc(sizeof(Node_t));

    new_node->key = key;
    new_node->value = value;
    new_node->next = ht[hv];
    ht[hv] = new_node;
    if (PRINT_CONTROL)
        printf("[INFO] INSERT %d successfully\n", key);
    return 1;
}

Node_t *chaining_search(Node_t **ht, int key)
{
    int hv = get_hash(key);
    Node_t *p = ht[hv];
    while (p && p->key != key)
        p = p->next;

    if (PRINT_CONTROL)
    {
        if (p)
            printf("[INFO] SEARCH key %d successfully \n", key);
        else
            printf("[INFO] SEARCH key %d does not exist \n", key);
    }
    return p;
}

int chaining_remove(Node_t **ht, int key)
{
    int hv = get_hash(key);
    if (!ht[hv])
    {

        if (PRINT_CONTROL)
            printf("[INFO] REMOVE key %d does not exist \n", key);
        return -1;
    }
    Node_t **p = &ht[hv];
    while (*p)
    {
        if ((*p)->key == key)
        {
            *p = (*p)->next;
            if (PRINT_CONTROL)
                printf("[INFO] REMOVE key %d successfully \n", key);
            return 0;
        }
        p = &((*p)->next);
    }

    if (PRINT_CONTROL)
        printf("[INFO] REMOVE key %d does not exist \n", key);
    return -1;
}

void chaining_print_table(Node_t **ht)
{
    if (PRINT_CONTROL)
        printf("[INFO] PRINT_TABLE \n");
    for (int i = 0; i < CHAINING_TABLE_SIZE; ++i)
    {
        if (ht[i])
        {
            printf("ht[%d] ==> ", i);
            Node_t *p = ht[i];
            while (p)
            {
                printf("[%d, %d]-> ", p->key, p->value);
                p = p->next;
            }
            printf("END\n");
        }
    }
}