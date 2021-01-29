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
	l_node* head = makeListNode(5);

	for (int i=0; i < 1000; i++){

		head = insertIntoList(rand(), head);
}
	printList(head);
	printf("sliced: \n");
	printList(sliceList(997,1001,head));
	return 0;
}
