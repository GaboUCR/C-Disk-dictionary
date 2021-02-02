#ifndef LINKEDLIST_H
#define LINKEDLIST_H

	typedef struct list_node {struct l_node* next; struct l_node* previous; int value; char* data;} l_node;

	l_node* makeListNode (int val, char data[]);

	l_node* sliceList (int start, int end, l_node* head);

	l_node* insertIntoList (int val, char data[], l_node* head);

	void printList(l_node* head);

#endif
