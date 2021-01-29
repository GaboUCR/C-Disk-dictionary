typedef enum {FALSE=0, TRUE=1} bool;

typedef struct node_t {struct node* left; struct node* right; int key; char* data;} node;

int makeKey(char keyword[]);

node* makeNode(int key, char data[]);
