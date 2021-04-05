#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include <string.h>
#include "Btree.h"
#include <time.h>
#include "linkedList.h"

int main(void){

	// char lolo[102] = "bastard:10234";
	// insert(lolo);
	int num = 0;
	l_node* l = makeListFromFile("Database", &num);

	printList(l);
	printf("\n");
	node* t = listToTree(l, num);
	printf("%s\n", getValue(getKeyToValue(t,makeKey("la loca de "))));
	// printTree(t);

	return 0;
}
