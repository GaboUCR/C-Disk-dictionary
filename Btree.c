#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include <string.h>
#include "Btree.h"

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
