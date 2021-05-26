#ifndef LINKEDLIST_H
#define LINKEDLIST_H

	typedef struct list_node {struct list_node* next; struct list_node* previous; char* key; char* value;} l_node;

	l_node* makeListNode (char* key, char* value);

	l_node* sliceList (int start, int end, l_node* head);

	l_node* insertIntoList (char* key, char* value, l_node* head);

	void printList(l_node* head);

#endif
