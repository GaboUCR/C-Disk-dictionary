#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include <string.h>
#include "Btree.h"
#include <time.h>
#include "linkedList.h"

int main(void){

	//char lolo[] = "pedro:12414242525";
	// char lola = "p";
	//
	//printf("keyword is: %d\n", makeKey(getKeyword(lolo)));
	// insert(lolo);
	// readEverything();

	srand(time(0));
	l_node* head = NULL;
	int numElements = 1023;

	for (int i=0; i < numElements; i++){

		head = insertIntoList(rand(), "patito",head);
	}

	//printList(head);
	node* treeHead = listToTree(head,numElements);
	int count = 0;
	for (int i =0; i<numElements; i++){

		int look = sliceList(i,i+1,head) -> value;
		int times = findValue(treeHead,look);

		if (times == 9){
			count++;
			// printf("%d\n", times);
		}

	}
	printf("%d\n", count);
	// printList(head);
	// printf("tree: \n");
	// printTree(treeHead);

	return 0;
}
