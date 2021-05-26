#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include <string.h>
#include "Btree.h"
#include "linkedList.h"

l_node* makeListNode (char key[], char value[]) {

	l_node* newElement = malloc(sizeof(l_node));
	newElement -> key = key;
	newElement -> value = value;
	newElement -> previous = NULL;
	newElement -> next = NULL;
	return newElement;
}

void getValue(char key[], l_node* head){
	l_node* current = head;

	while (current != NULL){

		if (strcmp(current -> key, key) == 0){
			printf("%s\n", current -> value);
		}
		current = current -> next;

	}

}

l_node* sliceList (int start, int end, l_node* head){

	l_node* current = head;
	l_node* newList = NULL;

	for(int i=0; i < end; i++) {

		if (i >= start){

			newList = insertIntoList(current -> key, current -> value ,newList);
		}
		current = current -> next;
	}
	return newList;
}

l_node* insertIntoList (char key[], char value[] ,l_node* head){

	l_node* newElement = makeListNode(key, value);
	//if head is null then we create the list
	if (head == NULL){
		return newElement;
	}

	int comp = strcmp(key, head -> key);

	if (comp > 0){

		head -> previous = newElement;
		newElement -> next = head;

		return newElement;
	}

	l_node* current = head->next;

	while(TRUE){
		comp = strcmp(key, current -> key);

		if (comp > 0){

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

		printf("%s:%s , ", current->key, current->value);
		current = current -> next;
	}

	printf("]");
}
