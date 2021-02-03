#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include <string.h>
#include "Btree.h"
#include "linkedList.h"

int makeKey(char keyword[]){

	int key = 0;

	for (int i=0; i < strlen(keyword); i++){

		key += keyword[i];

	}
	return key;
}

node* makeNode(int key, char data[]){

	node* newNode = malloc(sizeof(node));
	newNode -> data = &data[0];
	newNode -> key = key;
	newNode -> left = NULL;
	newNode -> right = NULL;

	return newNode;
}

node* listToTree (l_node* head, int length){

	if (length == 1){

		l_node* center = sliceList(0, 1, head);
		node* root = makeNode(center -> value, center -> data);
		return root;
	}

	if (length == 2){

		l_node* center = sliceList(1, 2, head);
		l_node* rightMost = sliceList(0, 1, head);

		node* root = makeNode(center -> value, center -> data);
		node* rightNode = makeNode(rightMost -> value, rightMost -> data);

		root -> right = rightNode;
		return root;
	}

	l_node* center = sliceList(length/2, length/2 + 1, head);
	// printList(center);
	l_node* right = sliceList(0, length/2, head);
	l_node* left = sliceList(length/2 +1, length, head);
	// printList(right);
	// printList(left);
	node* root = makeNode(center -> value, center -> data);

	node* leftBranch = listToTree(left, length - length/2 -1 );
	node* rightBranch = listToTree(right, length/2);

	root -> right = rightBranch;
	root -> left = leftBranch;

	return root;
}

char* getKeyToValue(node* head, int keyword){

	node* current = head;

	while (current != NULL){

		if (keyword == current -> key){

			return current -> data;
		}

		else if (keyword > current -> key ) {

			current = current -> right;
		}

		else if (keyword < current -> key){

			current = current -> left;
		}
	}

	return "";


}

void printTree(node* head){

	if (head != NULL){
		printf("the info is: %s and the value: %d \n", head -> data, head -> key);
		printTree(head->left);
		printTree(head->right);
	}

}
