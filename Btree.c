#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include <string.h>
#include "Btree.h"
#include "linkedList.h"


node* makeNode(char key[], char value[]){

	node* newNode = malloc(sizeof(node));
	newNode -> value = value;
	newNode -> key = key;
	newNode -> left = NULL;
	newNode -> right = NULL;

	return newNode;
}
// transforms the list that is saved in the file to a binary tree in memory
node* listToTree (l_node* head, int length){

	if (length == 1){

		l_node* center = sliceList(0, 1, head);
		node* root = makeNode(center -> key, center -> value);
		return root;
	}

	if (length == 2){

		l_node* center = sliceList(1, 2, head);
		l_node* rightMost = sliceList(0, 1, head);

		node* root = makeNode(center -> key, center -> value);
		node* rightNode = makeNode(rightMost -> key, rightMost -> value);

		root -> right = rightNode;
		return root;
	}
	l_node* center = sliceList(length/2, length/2 + 1, head);

	l_node* right = sliceList(0, length/2, head);
	l_node* left = sliceList(length/2 +1, length, head);
	node* root = makeNode(center -> key, center -> value);

	node* leftBranch = listToTree(left, length - length/2 -1 );
	node* rightBranch = listToTree(right, length/2);

	root -> right = rightBranch;
	root -> left = leftBranch;

	return root;
}
//
// char* getValue(node* head, char key[]){
//
// 	node* current = head;
//
// 	while (current != NULL){
//
// 		int comp = strcmp(key, current -> key);
//
// 		if (comp == 0){
//
// 			return current -> value;
// 		}
//
// 		else if (comp > 0) {
//
// 			current = current -> right;
// 		}
//
// 		else if (comp < 0){
//
// 			current = current -> left;
// 		}
// 	}
//
// 	return "";
// }

void printTree(node* head){

	if (head != NULL){
		printf("(%s:%s) \n", head -> key, head -> value);
		printTree(head->left);
		printTree(head->right);
	}

}

// void main(void){
//
// }
