#define CHAINING_TABLE_SIZE 1007

typedef struct Node
{
    int key;
    int value;
    struct Node *next;
} Node_t;

Node_t **chaining_create();
int chaining_insert(Node_t **ht, int key, int value);
Node_t *chaining_search(Node_t **ht, int key);
int chaining_remove(Node_t **ht, int key);
void chaining_print_table(Node_t **ht);