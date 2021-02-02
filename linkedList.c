#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include <string.h>
#include "Btree.h"
#include "linkedList.h"

l_node* makeListNode (int val, char data[])
{
	l_node* newElement = malloc(sizeof(l_node));
	newElement -> value = val;
	newElement -> data = &data[0];
	newElement -> previous = NULL;
	newElement -> next = NULL;

	return newElement;
}

l_node* sliceList (int start, int end, l_node* head){

	l_node* current = head;
	l_node* newList = NULL;

	for(int i=0; i < end; i++) {

		if (i >= start){

			newList = insertIntoList(current -> value, current -> data ,newList);
		}
		current = current -> next;
	}
	return newList;
}

l_node* insertIntoList (int val, char data[] ,l_node* head){

	l_node* newElement = makeListNode(val,data);

	//if head is null then we create the list
	if (head == NULL){
		return newElement;
	}

	l_node* current = head;

	if (head -> value < val){

		head -> previous = newElement;
		newElement -> next = head;

		return newElement;
	}

	while(TRUE){

		if (current->value < val){

			newElement -> previous = current -> previous;
			newElement -> next = current;

			l_node* prev = current -> previous;
			prev -> next = newElement;

			current -> previous = newElement;

			return head;
		}
			//check if it's the end
		if (current -> next == NULL){

			newElement -> previous = current;
			current -> next = newElement;

			return head;

		}
		current = current -> next;
	}

}

void printList(l_node* head){

	l_node* current = head;
	printf("[");

	while(current != NULL){
		printf("%d : %s, ", current->value, current->data);
		current = current -> next;
	}

	printf("]");
}
