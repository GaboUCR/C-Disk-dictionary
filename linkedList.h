typedef struct list_node {struct l_node* next; struct l_node* previous; int value;} l_node;

l_node* makeListNode (int val);

l_node* sliceList (int start, int end, l_node* head);

l_node* insertIntoList (int val, l_node* head);

void printList(l_node* head);
