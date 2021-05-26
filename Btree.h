#include "linkedList.h"

typedef enum {FALSE=0, TRUE=1} bool;

typedef struct node_t {struct node_t* left; struct node_t* right; char* key; char* value;} node;

node* makeNode(char* key, char* value);

node* listToTree (l_node* head, int length);

void printTree(node* head);

char* getValue(node* head, char key[]);
