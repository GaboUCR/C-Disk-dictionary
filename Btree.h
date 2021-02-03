#include "linkedList.h"

typedef enum {FALSE=0, TRUE=1} bool;

typedef struct node_t {struct node* left; struct node* right; int key; char* data;} node;

int makeKey(char keyword[]);

node* makeNode(int key, char data[]);

node* listToTree (l_node* head, int length);

void printTree(node* head);

char* getKeyToValue(node* head, int keyword);
